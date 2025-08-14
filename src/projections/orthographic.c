/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orthographic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:25:50 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:32:23 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_orthographic(t_render_task *task, t_vec3f rot)
{
	return ((t_vec3f){
		.x = rot.x * task->scale + task->x_offset,
		.y = rot.y * task->scale + task->y_offset,
		.z = rot.z + 10000.0f
	});
}
