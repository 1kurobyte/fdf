/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:22:28 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/11 22:27:19 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(size_t, char))
{
	char	*copy;
	size_t	i;

	copy = ft_strdup(s);
	i = 0;
	while (s[i])
	{
		copy[i] = f(i, s[i]);
		i++;
	}
	return (copy);
}
