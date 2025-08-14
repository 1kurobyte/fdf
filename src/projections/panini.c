/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:11:17 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:31:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_panini(t_render_task *task, t_vec3f rot)
{
	const float	d = 1.0f;
	const float	s = 1.0f;
	const float	xz = hypotf(rot.x, rot.z);
	float		x_pan;
	float		y_pan;

	if (rot.z < 0.0001f)
		return ((t_vec3f){INFINITY, INFINITY, INFINITY});
	x_pan = (d * rot.x) / (s * xz + (1.0f - s) * rot.z);
	y_pan = (d * rot.y) / rot.z;
	return ((t_vec3f){
		.x = x_pan * task->scale + task->x_offset,
		.y = y_pan * task->scale + task->y_offset,
		.z = rot.z
	});
}
