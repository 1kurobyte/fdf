/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu_steep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 21:08:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:31:36 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

static uint32_t	interp_alpha(uint32_t color, float alpha)
{
	return ((uint32_t)((uint8_t)(0xffu * (1.0f - alpha)) << 24u) | color);
}

static void	plot_first_point_steep(t_render_ctx *ctx, t_vertex v, float grad)
{
	const float	yend = roundf(v.p.y);
	const float	xend = v.p.x + grad * (yend - v.p.y);
	const float	ygap = rfpart(v.p.y + .5f);

	render_pixel(ctx, (t_vertex){{xend, yend, v.p.z},
		interp_alpha(v.c, rfpart(xend) * ygap)});
	render_pixel(ctx, (t_vertex){{xend + 1, yend, v.p.z},
		interp_alpha(v.c, fpart(xend) * ygap)});
}

static void	plot_second_point_steep(t_render_ctx *ctx, t_vertex v, float grad)
{
	const float	yend = roundf(v.p.y);
	const float	xend = v.p.x + grad * (yend - v.p.y);
	const float	ygap = fpart(v.p.y + .5f);

	render_pixel(ctx, (t_vertex){{xend, yend, v.p.z},
		interp_alpha(v.c, rfpart(xend) * ygap)});
	render_pixel(ctx, (t_vertex){{xend + 1, yend, v.p.z},
		interp_alpha(v.c, fpart(xend) * ygap)});
}

enum e_xiaolin_float_data
{
	INTERX,
	GRAD,
	DX,
	DY,
	DZ,
	Z,
	COUNT
};

static void	plot_line_points_steep(
	t_render_ctx *ctx, float fdata[COUNT], int32_t ypxl[2], t_vertex v[2])
{
	float		z;
	float		interx;
	int32_t		y;

	z = fdata[Z];
	interx = fdata[INTERX];
	y = ft_max(ypxl[0], 0);
	while (++y < ft_min(ypxl[1], ctx->height))
	{
		render_pixel(ctx, (t_vertex){{interx, (float)y, z},
			interp_alpha(lerp_u32(v[0].c, v[1].c, (float)y / (float)ypxl[1]),
				rfpart(interx))});
		render_pixel(ctx, (t_vertex){{interx + 1, (float)y, z},
			interp_alpha(lerp_u32(v[0].c, v[1].c, (float)y / (float)ypxl[1]),
				fpart(interx))});
		z += fdata[DZ];
		interx += fdata[GRAD];
	}
}

void	render_xiaolin_wu_steep(t_render_ctx *ctx, t_vertex v[2])
{
	float	fdata[COUNT];

	fdata[DX] = v[1].p.x - v[0].p.x;
	fdata[DY] = v[1].p.y - v[0].p.y;
	if (v[0].p.y > v[1].p.y)
	{
		swapf(&v[0].p.x, &v[1].p.x);
		swapf(&v[0].p.y, &v[1].p.y);
		swapf(&v[0].p.z, &v[1].p.z);
	}
	if (fdata[DX] == 0.0f && fdata[DY] == 0.0f)
	{
		render_pixel(ctx, v[0]);
		return ;
	}
	fdata[GRAD] = fdata[DX] / fdata[DY];
	fdata[INTERX] = v[0].p.x + fdata[GRAD];
	fdata[Z] = v[0].p.z;
	fdata[DZ] = (v[1].p.z - v[0].p.z) / fdata[DY];
	plot_first_point_steep(ctx, v[0], fdata[GRAD]);
	plot_second_point_steep(ctx, v[1], fdata[GRAD]);
	plot_line_points_steep(ctx, fdata,
		(int32_t[]){(int32_t)roundf(v[0].p.y), (int32_t)roundf(v[1].p.y)}, v);
}
