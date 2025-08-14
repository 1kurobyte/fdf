/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fisheye.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:20:25 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:32:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_fisheye(t_render_task *task, t_vec3f rot)
{
	const float	r = sqrtf(rot.x * rot.x + rot.y * rot.y);
	const float	theta = atan2f(r, rot.z);
	const float	scale = theta / (r + 0.000001f);

	return ((t_vec3f){
		.x = rot.x * scale * task->scale + task->x_offset,
		.y = rot.y * scale * task->scale + task->y_offset,
		.z = rot.z
	});
}
