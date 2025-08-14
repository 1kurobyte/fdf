/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:23:46 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/04 11:12:27 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "projections.h"

t_vec3f	project_conic(t_render_task *task, t_vec3f rot)
{
	const float	k = 0.01f;
	const float	curve = k * rot.y * rot.y;

	return ((t_vec3f){
		.x = rot.x * task->scale + task->x_offset,
		.y = (rot.z + curve) * task->scale + task->y_offset,
		.z = rot.z
	});
}
