/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:13:57 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:26:43 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/X.h>

static int	on_mouse_down(int button, int x, int y, t_fdf *fdf)
{
	struct s_mouse	*m;

	m = &fdf->input.mouse;
	m->x = x;
	m->y = y;
	if (button == 1)
		m->left = 1;
	else if (button == 2)
		m->middle = 1;
	else if (button == 3)
		m->right = 1;
	else if (button == 4)
		fdf->camera.scale = fminf(1.25f * fdf->camera.scale, 1000.0f);
	else if (button == 5)
		fdf->camera.scale = fmaxf(0.8f * fdf->camera.scale, 0.001f);
	else if (button == 8)
		cycle_projection_down(fdf);
	else if (button == 9)
		cycle_projection_up(fdf);
	if (m->initial_x == -1)
	{
		m->initial_x = x;
		m->initial_y = y;
	}
	return (0);
}

static int	on_mouse_up(int button, int x, int y, t_fdf *fdf)
{
	struct s_mouse	*m;

	m = &fdf->input.mouse;
	m->x = x;
	m->y = y;
	if (button == 1)
		m->left = 0;
	else if (button == 2)
		m->middle = 0;
	else if (button == 3)
		m->right = 0;
	if (!m->left && !m->right && !m->middle)
	{
		m->initial_x = -1;
		m->initial_y = -1;
	}
	return (0);
}

static int	on_mouse_move(int x, int y, t_fdf *fdf)
{
	fdf->input.mouse.x = x;
	fdf->input.mouse.y = y;
	return (0);
}

int	register_mouse_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->gfx.win, ButtonPress, ButtonPressMask, on_mouse_down, fdf);
	mlx_hook(fdf->gfx.win, ButtonRelease, ButtonReleaseMask, on_mouse_up, fdf);
	mlx_hook(fdf->gfx.win, MotionNotify, PointerMotionMask, on_mouse_move, fdf);
	return (0);
}
