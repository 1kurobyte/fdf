/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:25:51 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 09:18:21 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;

	save = NULL;
	if (!c)
		return ((char *)(intptr_t)s + ft_strlen(s));
	while (*s)
	{
		if (*s == (char)c)
			save = (char *)(intptr_t)s;
		s++;
	}
	return (save);
}
