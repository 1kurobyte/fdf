/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:49:23 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:26:56 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdint.h>

inline uint32_t	color_blend(uint32_t fg, uint32_t bg)
{
	const uint32_t	inv_a = color_get_a(fg) + 1;
	const uint32_t	a = 256 - inv_a;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;

	if (inv_a == 1)
		return (fg);
	if (inv_a == 256)
		return (bg);
	r = (uint8_t)((color_get_r(fg) * a + color_get_r(bg) * inv_a) >> 8);
	g = (uint8_t)((color_get_g(fg) * a + color_get_g(bg) * inv_a) >> 8);
	b = (uint8_t)((color_get_b(fg) * a + color_get_b(bg) * inv_a) >> 8);
	return (color_from_rgb(r, g, b));
}
