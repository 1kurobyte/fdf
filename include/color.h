/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:26:26 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:27:40 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

uint8_t		color_get_a(uint32_t c);
uint8_t		color_get_r(uint32_t c);
uint8_t		color_get_g(uint32_t c);
uint8_t		color_get_b(uint32_t c);

uint32_t	color_from_rgb(uint8_t r, uint8_t g, uint8_t b);
uint32_t	color_from_argb(uint8_t a, uint8_t r, uint8_t g, uint8_t b);
uint32_t	color_from_hsv(float h, float s, float v);

uint32_t	color_blend(uint32_t fg, uint32_t bg);
uint32_t	color_lerp(uint32_t c0, uint32_t c1, float t);

#endif
