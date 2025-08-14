/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:16:02 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 08:42:08 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTIONS_H
# define PROJECTIONS_H

# include "fdf.h"
# include "vectors.h"

typedef t_vec3f	(*t_projection_fn)(t_render_task *task, t_vec3f rot);

t_vec3f		project_orthographic(t_render_task *task, t_vec3f rot);
t_vec3f		project_perspective(t_render_task *task, t_vec3f rot);
t_vec3f		project_topdown(t_render_task *task, t_vec3f rot);
t_vec3f		project_conic(t_render_task *task, t_vec3f rot);
t_vec3f		project_fisheye(t_render_task *task, t_vec3f rot);
t_vec3f		project_spherical(t_render_task *task, t_vec3f rot);
t_vec3f		project_stereographic(t_render_task *task, t_vec3f rot);
t_vec3f		project_panini(t_render_task *task, t_vec3f rot);
// t_vec3f		project_logpolar(t_render_task *task, t_vec3f rot);

#endif
