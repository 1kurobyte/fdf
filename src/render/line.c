/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:52:57 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/31 16:48:09 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

void	render_line(t_render_ctx *ctx, t_vertex v[2], _Bool antialiased)
{
	if (antialiased)
	{
		if (fabsf(v[1].p.y - v[0].p.y) > fabsf(v[1].p.x - v[0].p.x))
			render_xiaolin_wu_steep(ctx, v);
		else
			render_xiaolin_wu(ctx, v);
	}
	else
		render_bresenham(ctx, v);
}
