/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topdown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:24:29 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:52:19 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_topdown(t_render_task *task, t_vec3f rot)
{
	return ((t_vec3f){
		.x = rot.x * task->scale + task->x_offset,
		.y = rot.z * task->scale + task->y_offset,
		.z = 1.0f
	});
}
