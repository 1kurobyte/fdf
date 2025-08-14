/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:23:24 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 10:23:45 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	update_camera_from_mouse(t_fdf *fdf)
{
	struct s_mouse	*m;
	struct s_camera	*cam ;
	const float		rot_step = 0.01f;

	m = &fdf->input.mouse;
	cam = &fdf->camera;
	if (!m->middle)
		return ;
	cam->rot.y += rot_step * (float)(m->x - m->initial_x);
	cam->rot.x += rot_step * (float)(m->y - m->initial_y);
	m->initial_x = m->x;
	m->initial_y = m->y;
}
