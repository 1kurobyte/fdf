/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:45:00 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:13:32 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdint.h>

#define FONT_GRID_SIZE 24
#define FONT_STEP 10

static inline uint32_t	to_alpha(uint32_t mask, uint32_t color)
{
	const uint8_t	alpha = (255 - (mask >> 16)) & 0xff;

	return (((uint32_t)alpha << 24) | color);
}

static void	draw_char(t_fdf *fdf, t_vec2f pos, char c, uint32_t color)
{
	int			i;
	int			j;
	uint32_t	final;
	uint32_t	*fg;

	fg = (uint32_t *)(void *)mlx_get_data_addr(fdf->gfx.font, &i, &i, &i);
	j = -1;
	while (++j < FONT_GRID_SIZE)
	{
		i = -1;
		while (++i < FONT_GRID_SIZE)
		{
			final = to_alpha(fg[(((c >> 4) - 2) * FONT_GRID_SIZE + j) * 16
					* FONT_GRID_SIZE + (c & 0xf) * FONT_GRID_SIZE + i], color);
			render_pixel(&fdf->rctx,
				(t_vertex){{pos.x + (float)i, pos.y + (float)j, 1}, final});
		}
	}
}

void	render_text(t_fdf *fdf, t_vec2f pos, const char *text,
		uint32_t color)
{
	int32_t	i;

	i = 0;
	while (*text)
	{
		draw_char(fdf, (t_vec2f){pos.x + (float)i, pos.y}, *text, color);
		i += FONT_STEP;
		text++;
	}
}
