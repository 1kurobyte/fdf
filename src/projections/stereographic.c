/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stereographic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:16:44 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:32:04 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_stereographic(t_render_task *task, t_vec3f rot)
{
	float	r2;
	float	scale;

	r2 = rot.x * rot.x + rot.y * rot.y + rot.z * rot.z;
	if (r2 < 0.000001f)
		return ((t_vec3f){INFINITY, INFINITY, INFINITY});
	scale = 1.0f / (1.0f + rot.z / sqrtf(r2));
	return ((t_vec3f){
		.x = rot.x * scale * task->scale + task->x_offset,
		.y = rot.y * scale * task->scale + task->y_offset,
		.z = rot.z
	});
}
