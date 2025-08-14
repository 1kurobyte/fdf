/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 23:29:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 09:58:12 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_internal.h"
#include <stddef.h>

char	*_ft_printf_strchr(const char *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)(intptr_t)s);
	return (NULL);
}

int	_ft_printf_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	_ft_printf_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- && s[i])
		i++;
	return (i);
}
