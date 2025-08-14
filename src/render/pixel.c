/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:25:24 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:45:55 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "render.h"
#include "fdf.h"
#include <pthread.h>
#include <stdint.h>

void	render_pixel(t_render_ctx *ctx, t_vertex v)
{
	const int32_t	x = (int32_t)v.p.x;
	const int32_t	y = (int32_t)v.p.y;
	uint32_t		*cbuf;
	float			*zbuf;
	float			invz;

	if (v.p.z <= 0.001f || isnan(v.p.z)
		|| x < 0 || y < 0 || x >= ctx->width || y >= ctx->height)
		return ;
	invz = 1.0f / v.p.z;
	zbuf = &ctx->invz_buf[y * ctx->width + x];
	cbuf = &ctx->clr_buf[y * ctx->width + x];
	if (invz > *zbuf)
	{
		*cbuf = v.c;
		*zbuf = invz;
	}
	else if (invz >= *zbuf)
		*cbuf = color_blend(v.c, *cbuf);
}

void	put_pixel_ui(t_render_ctx *ctx, int32_t x, int32_t y, uint32_t color)
{
	render_pixel(ctx, (t_vertex){{(float)x, (float)y, 1.0f}, color});
}

uint32_t	get_color(t_render_ctx *ctx, int32_t x, int32_t y)
{
	if (x < 0 || y < 0 || x >= ctx->width || y >= ctx->height)
		return (0);
	return (ctx->clr_buf[y * ctx->width + x]);
}
