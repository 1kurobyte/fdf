/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:32:01 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 09:23:39 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ = s;

	while (n--)
	{
		if (*s_ == (unsigned char)c)
			return ((void *)(intptr_t)s_);
		s_++;
	}
	return (NULL);
}
