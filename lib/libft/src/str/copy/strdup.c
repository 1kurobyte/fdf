/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:14:50 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/25 22:31:54 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;

	res = ft_malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s);
	return (res);
}
