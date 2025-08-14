/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:17:51 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:27:05 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdint.h>

inline uint32_t	color_lerp(uint32_t c0, uint32_t c1, float t)
{
	const uint8_t	r = (uint8_t)(color_get_r(c0)
			+ (color_get_r(c1) - color_get_r(c0)) * t);
	const uint8_t	g = (uint8_t)(color_get_g(c0)
			+ (color_get_g(c1) - color_get_g(c0)) * t);
	const uint8_t	b = (uint8_t)(color_get_b(c0)
			+ (color_get_b(c1) - color_get_b(c0)) * t);

	return (color_from_rgb(r, g, b));
}
