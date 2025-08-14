/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:25:15 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/04 11:14:34 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_perspective(t_render_task *task, t_vec3f rot)
{
	const float	safe_z = fmaxf(rot.z, 0.001f);
	const float	factor = 1.0f / safe_z;

	return ((t_vec3f){
		.x = rot.x * factor * task->scale + task->x_offset,
		.y = rot.y * factor * task->scale + task->y_offset,
		.z = rot.z
	});
}
