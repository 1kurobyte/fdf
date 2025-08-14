/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:58:19 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 11:00:55 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	auto const unsigned char *src_ = src;
	auto unsigned char *dst_ = dst;
	while (n-- && *src_ != c)
		*(dst_++) = *(src_++);
	if (n)
		*(dst_++) = (unsigned char)c;
	else
		return (0);
	return (dst_);
}
