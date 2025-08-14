/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:25:49 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 18:20:55 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>
#include <stdint.h>

struct s_hsv_to_rgb
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
};

static inline uint8_t	add_m(float v, float m)
{
	return ((uint8_t)((v + m) * 255));
}

static inline struct s_hsv_to_rgb	convert_color(
	float h, float c, float x, float m)
{
	if (h < 60)
		return ((struct s_hsv_to_rgb){add_m(c, m), add_m(x, m), add_m(0, m)});
	if (h < 120)
		return ((struct s_hsv_to_rgb){add_m(x, m), add_m(c, m), add_m(0, m)});
	if (h < 180)
		return ((struct s_hsv_to_rgb){add_m(0, m), add_m(c, m), add_m(x, m)});
	if (h < 240)
		return ((struct s_hsv_to_rgb){add_m(0, m), add_m(x, m), add_m(c, m)});
	if (h < 300)
		return ((struct s_hsv_to_rgb){add_m(x, m), add_m(0, m), add_m(c, m)});
	return ((struct s_hsv_to_rgb){add_m(c, m), add_m(0, m), add_m(x, m)});
}

uint32_t	color_from_hsv(float h, float s, float v)
{
	const float			c = v * s;
	const float			x = c * (1 - fabsf(fmodf(h / 60.0f, 2) - 1));
	const float			m = v - c;
	struct s_hsv_to_rgb	t;

	t = convert_color(h, c, x, m);
	return ((uint32_t)(t.r << 16) | (uint32_t)(t.g << 8) | t.b);
}
