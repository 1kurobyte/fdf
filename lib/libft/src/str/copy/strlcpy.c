/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:16:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:33:10 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	if (dsize > 0)
		dst[0] = 0;
	if (dsize == 0)
		return (ft_strlen(src));
	return (ft_strlcat(dst, src, dsize));
}
