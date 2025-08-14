/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:38:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:04:13 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vectors.h"
#include <stdint.h>

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

static inline void	line_horiz(t_fdf *fdf, t_render_task *task, int i, int j)
{
	t_vec3f	p0;
	t_vec3f	p1;
	float	y0;
	float	y1;

	if (j >= fdf->map.width - 1)
		return ;
	p0 = project_point(fdf, task, i, j);
	p1 = project_point(fdf, task, i, j + 1);
	if (out_of_bounds(vec3f_to_2i(p0), fdf->window.width,
			fdf->window.height)
		&& out_of_bounds(vec3f_to_2i(p1), fdf->window.width,
			fdf->window.height))
		return ;
	y0 = (float)fdf->map.elevation[i * fdf->map.width + j];
	y1 = (float)fdf->map.elevation[i * fdf->map.width + j + 1];
	render_line(&task->ctx, (t_vertex[2]){
	{p0, terrain_color(y0, (float)fdf->map.alt_min, (float)fdf->map.alt_max)},
	{p1, terrain_color(y1, (float)fdf->map.alt_min, (float)fdf->map.alt_max)}},
		fdf->state.antialiasing);
}

static inline void	line_vert(t_fdf *fdf, t_render_task *task, int i, int j)
{
	t_vec3f	p0;
	t_vec3f	p1;
	float	y0;
	float	y1;

	if (i >= fdf->map.height - 1)
		return ;
	p0 = project_point(fdf, task, i, j);
	p1 = project_point(fdf, task, i + 1, j);
	if (out_of_bounds(vec3f_to_2i(p0), fdf->window.width,
			fdf->window.height)
		&& out_of_bounds(vec3f_to_2i(p1), fdf->window.width,
			fdf->window.height))
		return ;
	y0 = (float)fdf->map.elevation[i * fdf->map.width + j];
	y1 = (float)fdf->map.elevation[(i + 1) * fdf->map.width + j];
	render_line(&task->ctx, (t_vertex[2]){
	{p0, terrain_color(y0, (float)fdf->map.alt_min, (float)fdf->map.alt_max)},
	{p1, terrain_color(y1, (float)fdf->map.alt_min, (float)fdf->map.alt_max)}},
		fdf->state.antialiasing);
}

void	render_lines(t_fdf *fdf, t_render_task *task, int i, int j)
{
	line_horiz(fdf, task, i, j);
	line_vert(fdf, task, i, j);
}
