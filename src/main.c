/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:02:40 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:45:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "fdf.h"
#include "cli.h"
#include "libft.h"
#include "mlx.h"
#include "render.h"
#include "threads.h"
#include "vectors.h"
#include "worldgen.h"
#include "camera.h"
#include <X11/X.h>
#include <float.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>

int	fdf_destroy(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i < NUM_THREADS)
	{
		free(fdf->clr_bufs[i]);
		free(fdf->invz_bufs[i]);
	}
	free(fdf->rctx.clr_buf);
	free(fdf->rctx.invz_buf);
	gfx_destroy(&fdf->gfx);
	threadpool_destroy(&fdf->pool);
	free(fdf->map.elevation);
	exit(0);
	return (0);
}

__attribute__((__always_inline__))
static void	limit_frames(struct timeval start, struct timeval end)
{
	struct timespec	ts;
	long			dt;

	dt = (end.tv_sec - start.tv_sec) * 1000000L + (end.tv_usec - start.tv_usec);
	if (dt < FRAME_TIME_US)
	{
		ts = (struct timespec){0, .tv_nsec = (FRAME_TIME_US - dt * 1000L)};
		nanosleep(&ts, NULL);
	}
}

static int	loop(t_fdf *fdf)
{
	struct timeval	start;
	struct timeval	end;
	t_render_task	tasks[NUM_THREADS];

	gettimeofday(&start, NULL);
	update_camera_from_keys(fdf);
	clear_framebuffers(fdf);
	init_tasks(fdf, tasks);
	threadpool_run(&fdf->pool);
	ui_render(fdf);
	display_projection_type(fdf);
	draw_gimbal(fdf);
	if (fdf->state.show_depth)
		render_depth(fdf);
	else
		merge_framebuffers(fdf);
	mlx_put_image_to_window(fdf->gfx.mlx, fdf->gfx.win, fdf->gfx.frame, 0, 0);
	gettimeofday(&end, NULL);
	limit_frames(start, end);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_memset(&fdf, 0, sizeof(t_fdf));
	fdf.window.width = 1200;
	fdf.window.height = 800;
	fdf.camera.height_scale = 0.01f;
	fdf.camera.scale = 0.5f;
	fdf.camera.mode = PROJ_ORTHO;
	if (arguments_init(&fdf, argc, argv) != RESULT_OK
		|| options_init(&fdf.opts) != RESULT_OK
		|| worldgen_init(&fdf, argv[1]) != RESULT_OK
		|| gfx_init(&fdf.gfx, fdf.opts) != RESULT_OK
		|| threadpool_init(&fdf.pool) != RESULT_OK
		|| framebuffers_init(&fdf) != RESULT_OK)
		return (fdf_destroy(&fdf), 1);
	ui_init(&fdf);
	register_hooks(&fdf);
	mlx_loop_hook(fdf.gfx.mlx, loop, &fdf);
	mlx_loop(fdf.gfx.mlx);
	fdf_destroy(&fdf);
}
