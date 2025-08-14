/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:38:26 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:52:45 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

__attribute__((__always_inline__))
static inline void	init_task_ctx(t_render_task *task, int t)
{
	const int32_t	width = task->fdf->window.width;
	const int32_t	height = task->fdf->window.height;

	task->ctx = (t_render_ctx){
		.data = task->fdf,
		.width = width,
		.height = height,
		.clr_buf = task->fdf->clr_bufs[t],
		.invz_buf = task->fdf->invz_bufs[t]
	};
}

void	init_tasks(t_fdf *fdf, t_render_task *tasks)
{
	int		t;
	int32_t	chunk;

	t = -1;
	chunk = (fdf->map.height + NUM_THREADS - 1) / NUM_THREADS;
	while (++t < NUM_THREADS)
	{
		tasks[t].index = t;
		tasks[t].fdf = fdf;
		tasks[t].cam = &fdf->camera;
		tasks[t].view = get_view_matrix(&fdf->camera);
		tasks[t].scale = fdf->camera.scale;
		if (fdf->camera.mode == PROJ_PERSPECTIVE)
			tasks[t].scale *= 200.0f;
		tasks[t].height_scale = fdf->camera.height_scale;
		tasks[t].x_offset = 0.5f * (float)fdf->window.width;
		tasks[t].y_offset = 0.5f * (float)fdf->window.height;
		tasks[t].min_alt = fdf->map.alt_min;
		tasks[t].max_alt = fdf->map.alt_max;
		tasks[t].row_start = t * chunk;
		tasks[t].row_end = ft_min((t + 1) * chunk, fdf->map.height);
		init_task_ctx(&tasks[t], t);
		threadpool_add(&fdf->pool, render_task, &tasks[t]);
	}
}

void	render_task(void *arg)
{
	t_render_task	*task;
	t_fdf			*fdf;
	int32_t			i;
	int32_t			j;

	task = (t_render_task *)arg;
	fdf = task->fdf;
	i = task->row_start - 1;
	if (!fdf->map.elevation)
		return ;
	while (++i < task->row_end)
	{
		j = -1;
		while (++j < fdf->map.width - 1)
		{
			render_faces(fdf, task, i, j);
			render_lines(fdf, task, i, j);
		}
	}
}
