/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mempcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:41:42 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 09:23:15 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dst;
	while (n--)
		*d++ = *s++;
	return (d);
}
