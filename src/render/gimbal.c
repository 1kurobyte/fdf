/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gimbal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:49:30 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:46:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "vectors.h"
#include <stdint.h>

#define GIMBAL_SEGMENTS 64

static t_vec3f	project(t_fdf *fdf, t_vec3f p)
{
	const float	scale = 40.0f;
	const float	x_offset = (float)(fdf->window.width - 50);
	const float	y_offset = 50;

	return ((t_vec3f){
		.x = p.x * scale + x_offset,
		.y = p.y * scale + y_offset,
		.z = 1.0f
	});
}

static void	draw_x_axis(t_fdf *fdf, uint32_t color)
{
	t_vec3f			p0;
	t_vec3f			p1;
	float			a0;
	float			a1;
	int				i;

	i = -1;
	while (++i < GIMBAL_SEGMENTS)
	{
		a0 = (2.0f * M_PIf * (float)i) / GIMBAL_SEGMENTS;
		a1 = (2.0f * M_PIf * (float)(i + 1)) / GIMBAL_SEGMENTS;
		p0 = (t_vec3f){0, cosf(a0), sinf(a0)};
		p1 = (t_vec3f){0, cosf(a1), sinf(a1)};
		p0 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p0);
		p1 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p1);
		render_line(&fdf->rctx, (t_vertex[2]){{project(fdf, p0), color},
		{project(fdf, p1), color}}, true);
	}
}

static void	draw_y_axis(t_fdf *fdf, uint32_t color)
{
	t_vec3f			p0;
	t_vec3f			p1;
	float			a0;
	float			a1;
	int				i;

	i = -1;
	while (++i < GIMBAL_SEGMENTS)
	{
		a0 = (2.0f * M_PIf * (float)i) / GIMBAL_SEGMENTS;
		a1 = (2.0f * M_PIf * (float)(i + 1)) / GIMBAL_SEGMENTS;
		p0 = (t_vec3f){cosf(a0), 0, sinf(a0)};
		p1 = (t_vec3f){cosf(a1), 0, sinf(a1)};
		p0 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p0);
		p1 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p1);
		render_line(&fdf->rctx, (t_vertex[2]){{project(fdf, p0), color},
		{project(fdf, p1), color}}, true);
	}
}

static void	draw_z_axis(t_fdf *fdf, uint32_t color)
{
	t_vec3f			p0;
	t_vec3f			p1;
	float			a0;
	float			a1;
	int				i;

	i = -1;
	while (++i < GIMBAL_SEGMENTS)
	{
		a0 = (2.0f * M_PIf * (float)i) / GIMBAL_SEGMENTS;
		a1 = (2.0f * M_PIf * (float)(i + 1)) / GIMBAL_SEGMENTS;
		p0 = (t_vec3f){cosf(a0), sinf(a0), 0};
		p1 = (t_vec3f){cosf(a1), sinf(a1), 0};
		p0 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p0);
		p1 = mat3f_vec_mult(get_view_matrix(&fdf->camera), p1);
		render_line(&fdf->rctx, (t_vertex[2]){{project(fdf, p0), color},
		{project(fdf, p1), color}}, true);
	}
}

void	draw_gimbal(t_fdf *fdf)
{
	draw_x_axis(fdf, 0xff8000);
	draw_y_axis(fdf, 0x80ff00);
	draw_z_axis(fdf, 0x0080ff);
}
