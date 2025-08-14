/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:49:00 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 08:07:19 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "vectors.h"
#include "render.h"
#include "libft.h"
#include <stdint.h>

typedef struct __attribute__((aligned(16))) s_weighted_color
{
	uint32_t	c;
	float		w;
	char		reserved[8];
}	t_weighted_color;

static inline uint32_t	mix_colors(
	t_weighted_color c0,
	t_weighted_color c1,
	t_weighted_color c2)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;

	r = (uint8_t)(c0.w * color_get_r(c0.c)
			+ c1.w * color_get_r(c1.c)
			+ c2.w * color_get_r(c2.c));
	g = (uint8_t)(c0.w * color_get_g(c0.c)
			+ c1.w * color_get_g(c1.c)
			+ c2.w * color_get_g(c2.c));
	b = (uint8_t)(c0.w * color_get_b(c0.c)
			+ c1.w * color_get_b(c1.c)
			+ c2.w * color_get_b(c2.c));
	return (color_from_rgb(r, g, b));
}

static inline int	edge(t_vec2i a, t_vec2i b, t_vec2i p)
{
	return ((p.x - a.x) * (b.y - a.y) - (p.y - a.y) * (b.x - a.x));
}

static void	render_triangle_pixel(
	t_render_ctx *ctx, t_vec2i pc, t_vertex v[3], float area)
{
	const t_vec2i	p[3] = {
		vec3f_to_2i(v[0].p),
		vec3f_to_2i(v[1].p),
		vec3f_to_2i(v[2].p)};
	const float		w[3] = {
		(float)edge(p[1], p[2], pc) / area,
		(float)edge(p[2], p[0], pc) / area,
		(float)edge(p[0], p[1], pc) / area};
	float			z;
	uint32_t		color;

	if (w[0] < 0 || w[1] < 0 || w[2] < 0)
		return ;
	z = w[0] * v[0].p.z + w[1] * v[1].p.z + w[2] * v[2].p.z;
	color = mix_colors(
			(t_weighted_color){v[0].c, w[0], {0}},
			(t_weighted_color){v[1].c, w[1], {0}},
			(t_weighted_color){v[2].c, w[2], {0}});
	render_pixel(ctx,
		(t_vertex){{.x = (float)pc.x, .y = (float)pc.y, .z = z}, color});
}

enum e_triangle_data
{
	CUR,
	MIN,
	MAX,
	COUNT
};

void	render_triangle(t_render_ctx *ctx, t_vertex v[3])
{
	const t_vec2i	p[3] = {
		vec3f_to_2i(v[0].p),
		vec3f_to_2i(v[1].p),
		vec3f_to_2i(v[2].p)};
	const float		area = (float)edge(p[0], p[1], p[2]);
	int32_t			x[COUNT];
	int32_t			y[COUNT];

	x[MIN] = ft_max(0, ft_min(p[0].x, ft_min(p[1].x, p[2].x)));
	x[MAX] = ft_min(ctx->width, ft_max(p[0].x, ft_max(p[1].x, p[2].x)));
	y[MIN] = ft_max(0, ft_min(p[0].y, ft_min(p[1].y, p[2].y)));
	y[MAX] = ft_min(ctx->height, ft_max(p[0].y, ft_max(p[1].y, p[2].y)));
	y[CUR] = y[MIN];
	while (y[CUR] < y[MAX])
	{
		x[CUR] = x[MIN];
		while (x[CUR] < x[MAX])
		{
			render_triangle_pixel(ctx, (t_vec2i){x[CUR], y[CUR]}, v, area);
			x[CUR]++;
		}
		y[CUR]++;
	}
}
