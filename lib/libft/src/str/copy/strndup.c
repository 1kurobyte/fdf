/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:09:04 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:31:51 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, const size_t n)
{
	size_t	i;
	char	*res;

	res = ft_malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	i = (size_t)-1;
	while (++i < n)
		res[i] = s[i];
	res[i] = 0;
	return (res);
}
