/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:45:16 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 18:13:13 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "render.h"
#include "libft.h"
#include <math.h>
#include <stdint.h>

static float	lerpf(float a, float b, float t)
{
	return (a + (b - a) * t);
}

enum e_bresenham_data
{
	X = 0,
	Y = 1,
	DX = 2,
	DY = 3,
	SX = 4,
	SY = 5,
	STEPS = 6,
	ERR = 7,
	COUNT = 8
};

static void	plot_points(
	t_render_ctx *ctx, t_vertex v[2], int32_t data[COUNT])
{
	int32_t		i;
	int32_t		e2;
	float		t;

	i = -1;
	while (++i <= data[STEPS])
	{
		t = 0.0f;
		if (data[STEPS])
			t = (float)i / (float)data[STEPS];
		render_pixel(ctx, (t_vertex){{(float)data[X], (float)data[Y],
			lerpf(v[0].p.z, v[1].p.z, t)},
			color_lerp(v[0].c, v[1].c, t)});
		e2 = data[ERR] * 2;
		if (e2 > -data[DY])
		{
			data[ERR] -= data[DY];
			data[X] += data[SX];
		}
		if (e2 < data[DX])
		{
			data[ERR] += data[DX];
			data[Y] += data[SY];
		}
	}
}

void	render_bresenham(t_render_ctx *ctx, t_vertex v[2])
{
	int32_t	data[COUNT];

	v[0].p.x = floorf(v[0].p.x);
	v[1].p.x = floorf(v[1].p.x);
	v[0].p.y = floorf(v[0].p.y);
	v[1].p.y = floorf(v[1].p.y);
	data[DX] = (int32_t)fabsf(v[1].p.x - v[0].p.x);
	data[DY] = (int32_t)fabsf(v[1].p.y - v[0].p.y);
	data[STEPS] = ft_max(data[DX], data[DY]);
	data[SX] = ((v[0].p.x < v[1].p.x) << 1) - 1;
	data[SY] = ((v[0].p.y < v[1].p.y) << 1) - 1;
	data[ERR] = data[DX] - data[DY];
	data[X] = (int32_t)v[0].p.x;
	data[Y] = (int32_t)v[0].p.y;
	plot_points(ctx, v, data);
}
