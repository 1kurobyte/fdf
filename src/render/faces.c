/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:38:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:46:47 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static inline bool	out_of_bounds(t_vec2i p, int w, int h)
{
	return (p.x < 0 || p.x >= w || p.y < 0 || p.y >= h);
}

typedef struct s_colorstop {
	float		t;
	uint32_t	c;
}	t_colorstop;

static uint32_t	terrain_color(float y, float min_y, float max_y)
{
	float				norm;
	uint32_t			i;
	static t_colorstop	stops[] = {
	{-1.00f, 0x001f5f},
	{-0.75f, 0x003f7f},
	{-0.20f, 0x005f9f},
	{0.234f, 0x009fdf},
	{0.24f, 0xf0e0b0},
	{0.25f, 0x88c070},
	{0.50f, 0x558c4e},
	{0.60f, 0x666666},
	{0.80f, 0xaaaaaa},
	{0.95f, 0xffffff},
	{1.00f, 0xf8f8f8}};

	norm = 2.0f * (y - min_y) / (max_y - min_y) - 1.0f;
	i = (uint32_t)-1;
	while (++i < sizeof(stops) / sizeof(stops[0]) - 1)
	{
		if (norm >= stops[i].t && norm <= stops[i + 1].t)
			return (color_lerp(stops[i].c, stops[i + 1].c,
					(norm - stops[i].t) / (stops[i + 1].t - stops[i].t)));
	}
	return (stops[sizeof(stops) / sizeof(stops[0]) - 1].c);
}

static inline void	render_face(t_fdf *fdf, t_render_task *task,
	t_vec3f v[3], float alt[3])
{
	if (out_of_bounds(vec3f_to_2i(v[0]),
			fdf->window.width, fdf->window.height)
		&& out_of_bounds(vec3f_to_2i(v[1]),
			fdf->window.width, fdf->window.height)
		&& out_of_bounds(vec3f_to_2i(v[2]),
			fdf->window.width, fdf->window.height))
		return ;
	if (fdf->state.face_filling)
		render_triangle(&task->ctx, (t_vertex[3]){
		{v[0], terrain_color(alt[0],
				(float)fdf->map.alt_min, (float)fdf->map.alt_max)},
		{v[1], terrain_color(alt[1],
				(float)fdf->map.alt_min, (float)fdf->map.alt_max)},
		{v[2], terrain_color(alt[2],
				(float)fdf->map.alt_min, (float)fdf->map.alt_max)}});
	else if (fdf->state.culling)
		render_triangle(&task->ctx,
			(t_vertex[3]){{{v[0].x, v[0].y, v[0].z + 0.1f}, 0},
		{{v[1].x, v[1].y, v[1].z + 0.01f}, 0},
		{{v[2].x, v[2].y, v[2].z + 0.01f}, 0}});
}

void	render_faces(t_fdf *fdf, t_render_task *task, int i, int j)
{
	t_vec3f	p0;
	t_vec3f	p1;
	t_vec3f	p2;
	t_vec3f	p3;

	if (i >= fdf->map.height - 1 || j >= fdf->map.width - 1)
		return ;
	p0 = project_point(fdf, task, i, j);
	p1 = project_point(fdf, task, i, j + 1);
	p2 = project_point(fdf, task, i + 1, j);
	p3 = project_point(fdf, task, i + 1, j + 1);
	render_face(fdf, task, (t_vec3f[3]){p0, p1, p2}, (float [3]){
		(float)fdf->map.elevation[i * fdf->map.width + j],
		(float)fdf->map.elevation[i * fdf->map.width + j + 1],
		(float)fdf->map.elevation[(i + 1) * fdf->map.width + j],
	});
	render_face(fdf, task, (t_vec3f[3]){p1, p2, p3}, (float [3]){
		(float)fdf->map.elevation[i * fdf->map.width + j + 1],
		(float)fdf->map.elevation[(i + 1) * fdf->map.width + j],
		(float)fdf->map.elevation[(i + 1) * fdf->map.width + j + 1],
	});
}
