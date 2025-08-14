/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:23:12 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:24:30 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <stdint.h>

uint32_t	color_from_rgb(uint8_t r, uint8_t g, uint8_t b)
{
	return ((uint32_t)((r << 16) | (g << 8) | b));
}

uint32_t	color_from_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	return ((uint32_t)((a << 24) | (r << 16) | (g << 8) | b));
}
