/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:23:34 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:30:55 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

static int	on_key_press(int keysym, t_fdf *fdf)
{
	if (keysym == XK_w)
		fdf->input.keys.forward = 1;
	else if (keysym == XK_s)
		fdf->input.keys.backward = 1;
	else if (keysym == XK_a)
		fdf->input.keys.left = 1;
	else if (keysym == XK_d)
		fdf->input.keys.right = 1;
	else if (keysym == XK_space)
		fdf->input.keys.up = 1;
	else if (keysym == XK_c)
		fdf->input.keys.down = 1;
	else if (keysym == XK_Left)
		fdf->input.keys.yaw_left = 1;
	else if (keysym == XK_Right)
		fdf->input.keys.yaw_right = 1;
	else if (keysym == XK_Up)
		fdf->input.keys.pitch_up = 1;
	else if (keysym == XK_Down)
		fdf->input.keys.pitch_down = 1;
	else if (keysym == XK_m)
		cycle_projection_up(fdf);
	return (0);
}

static int	on_key_release(int keysym, t_fdf *fdf)
{
	t_keys	*keys;

	keys = &fdf->input.keys;
	if (keysym == XK_w)
		keys->forward = 0;
	else if (keysym == XK_s)
		keys->backward = 0;
	else if (keysym == XK_a)
		keys->left = 0;
	else if (keysym == XK_d)
		keys->right = 0;
	else if (keysym == XK_space)
		keys->up = 0;
	else if (keysym == XK_c)
		keys->down = 0;
	else if (keysym == XK_Left)
		keys->yaw_left = 0;
	else if (keysym == XK_Right)
		keys->yaw_right = 0;
	else if (keysym == XK_Up)
		keys->pitch_up = 0;
	else if (keysym == XK_Down)
		keys->pitch_down = 0;
	return (0);
}

int	register_key_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->gfx.win, KeyPress, KeyPressMask, on_key_press, fdf);
	mlx_hook(fdf->gfx.win, KeyRelease, KeyReleaseMask, on_key_release, fdf);
	return (0);
}
