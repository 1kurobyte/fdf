/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 10:13:16 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(const char *s, size_t start, size_t size)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strnlen(s + start, size) < size)
		size = ft_strnlen(s + start, size);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	i = (size_t)-1;
	while (++i < size)
		res[i] = s[start + i];
	res[i] = 0;
	return (res);
}
