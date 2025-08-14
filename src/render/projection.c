/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:50:17 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:07:42 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "projections.h"

static t_projection_fn	get_projection(t_projection_mode mode)
{
	return ((t_projection_fn[]){
		project_orthographic,
		project_perspective,
		project_topdown,
		project_conic,
		project_fisheye,
		project_spherical,
		project_stereographic,
		project_panini,
	}[mode]);
}

t_vec3f	project_point(t_fdf *fdf, t_render_task *task, int i, int j)
{
	t_camera	*cam;
	t_vec3f		world;
	t_vec3f		relative;
	t_vec3f		rot;

	world = (t_vec3f){
		.x = (float)j - (float)fdf->map.width * 0.5f,
		.y = (float)fdf->map.elevation[i * fdf->map.width + j]
		* task->height_scale,
		.z = (float)i - (float)fdf->map.height * 0.5f
	};
	cam = &fdf->camera;
	relative = vec3f_sub(world, cam->pos);
	rot = relative;
	if (cam->mode != PROJ_TOPDOWN)
		rot = mat3f_vec_mult(task->view, relative);
	return (get_projection(cam->mode)(task, rot));
}

void	display_projection_type(t_fdf *fdf)
{
	const char		*name = (const char *[PROJ_COUNT]){
		"Orthographic",
		"Perspective",
		"Top Down",
		"Conic",
		"Fisheye",
		"Spherical",
		"Stereographic",
		"Panini",
	}[fdf->camera.mode];
	const size_t	len = ft_strlen(name) + 1;

	render_text(fdf, (t_vec2f){
		0.5f * (float)(fdf->window.width - FONT_STEP * (int32_t)len),
		16}, name, 0x00ff00);
}

void	cycle_projection_up(t_fdf *fdf)
{
	fdf->camera.mode = (fdf->camera.mode + 1) % PROJ_COUNT;
}

void	cycle_projection_down(t_fdf *fdf)
{
	fdf->camera.mode = (fdf->camera.mode + PROJ_COUNT - 1) % PROJ_COUNT;
}
