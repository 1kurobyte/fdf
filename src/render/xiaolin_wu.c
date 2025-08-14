/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xiaolin_wu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:55:31 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/12 08:01:28 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "render.h"
#include <stdint.h>

static uint32_t	interp_alpha(uint32_t color, float alpha)
{
	return (((uint32_t)((uint8_t)(0xffu * (1.0f - alpha))) << 24) | color);
}

static void	plot_first_point(t_render_ctx *ctx, t_vertex v, float grad)
{
	const float		xend = roundf(v.p.x);
	const float		yend = v.p.y + grad * (xend - v.p.x);
	const float		xgap = rfpart(v.p.x + .5f);

	render_pixel(ctx, (t_vertex){{xend, yend, v.p.z},
		interp_alpha(v.c, rfpart(yend) * xgap)});
	render_pixel(ctx, (t_vertex){{xend, yend + 1, v.p.z},
		interp_alpha(v.c, fpart(yend) * xgap)});
}

static void	plot_second_point(t_render_ctx *ctx, t_vertex v, float grad)
{
	const float		xend = roundf(v.p.x);
	const float		yend = v.p.y + grad * (xend - v.p.x);
	const float		xgap = fpart(v.p.x + .5f);

	render_pixel(ctx, (t_vertex){{xend, yend, v.p.z},
		interp_alpha(v.c, rfpart(yend) * xgap)});
	render_pixel(ctx, (t_vertex){{xend, yend + 1, v.p.z},
		interp_alpha(v.c, fpart(yend) * xgap)});
}

enum e_xiaolin_float_data
{
	INTERY,
	GRAD,
	DX,
	DY,
	DZ,
	Z,
	COUNT
};

static void	plot_line_points(
	t_render_ctx *ctx, float fdata[COUNT], int32_t xpxl[2], t_vertex v[2])
{
	float		z;
	float		intery;
	int32_t		x;

	z = fdata[Z];
	intery = fdata[INTERY];
	x = ft_max(xpxl[0], 0);
	while (++x < ft_min(xpxl[1], ctx->width))
	{
		render_pixel(ctx, (t_vertex){{(float)x, floorf(intery), z},
			interp_alpha(lerp_u32(v[0].c, v[1].c, (float)x / (float)xpxl[1]),
				rfpart(intery))});
		render_pixel(ctx, (t_vertex){{(float)x, floorf(intery) + 1, z},
			interp_alpha(lerp_u32(v[0].c, v[1].c, (float)x / (float)xpxl[1]),
				fpart(intery))});
		z += fdata[DZ];
		intery += fdata[GRAD];
	}
}

void	render_xiaolin_wu(t_render_ctx *ctx, t_vertex v[2])
{
	float	fdata[COUNT];

	fdata[DX] = v[1].p.x - v[0].p.x;
	fdata[DY] = v[1].p.y - v[0].p.y;
	if (v[0].p.x > v[1].p.x)
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
	fdata[GRAD] = fdata[DY] / fdata[DX];
	fdata[INTERY] = v[0].p.y + fdata[GRAD];
	fdata[Z] = v[0].p.z;
	fdata[DZ] = (v[1].p.z - v[0].p.z) / fdata[DX];
	plot_first_point(ctx, v[0], fdata[GRAD]);
	plot_second_point(ctx, v[1], fdata[GRAD]);
	plot_line_points(ctx, fdata,
		(int32_t[]){(int32_t)roundf(v[0].p.x), (int32_t)roundf(v[1].p.x)}, v);
}
