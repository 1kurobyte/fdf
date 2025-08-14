/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:45:10 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 08:36:33 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "color.h"
# include "vectors.h"
# include <stdint.h>

typedef struct s_vertex
{
	t_vec3f		p;
	uint32_t	c;
}	t_vertex;

typedef void	(*t_render_put_pixel_fn)(void *data, t_vertex v);

typedef struct s_render_ctx
{
	void		*data;
	uint32_t	*clr_buf;
	float		*invz_buf;
	int32_t		width;
	int32_t		height;
}	t_render_ctx;

void	render_bresenham(t_render_ctx *ctx, t_vertex v[2]);
void	render_xiaolin_wu(t_render_ctx *ctx, t_vertex v[2]);
void	render_xiaolin_wu_steep(t_render_ctx *ctx, t_vertex v[2]);

void	render_pixel(t_render_ctx *ctx, t_vertex v);
void	render_line(t_render_ctx *ctx, t_vertex v[2], _Bool antialiased);
void	render_triangle(t_render_ctx *ctx, t_vertex v[3]);
void	render_rect(t_render_ctx *ctx, t_vertex v[4]);

#endif
