/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spherical.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:18:38 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:31:19 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_spherical(t_render_task *task, t_vec3f rot)
{
	float	r;
	float	theta;
	float	phi;

	r = sqrtf(rot.x * rot.x + rot.y * rot.y + rot.z * rot.z);
	if (r < 0.000001f)
		return ((t_vec3f){INFINITY, INFINITY, INFINITY});
	theta = atan2f(rot.x, rot.z);
	phi = asinf(rot.y / r);
	return ((t_vec3f){
		.x = theta * task->scale + task->x_offset,
		.y = -phi * task->scale + task->y_offset,
		.z = rot.z
	});
}
