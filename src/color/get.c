/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:58:25 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 11:58:31 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

inline uint8_t	color_get_a(uint32_t c)
{
	return ((c >> 24) & 0xff);
}

inline uint8_t	color_get_r(uint32_t c)
{
	return ((c >> 16) & 0xff);
}

inline uint8_t	color_get_g(uint32_t c)
{
	return ((c >> 8) & 0xff);
}

inline uint8_t	color_get_b(uint32_t c)
{
	return (c & 0xff);
}
