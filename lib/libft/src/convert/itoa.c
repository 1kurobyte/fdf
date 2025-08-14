/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:14:24 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:29:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;

	i = ft_intlen(n);
	buf = ft_malloc((size_t)i + 1);
	if (!buf)
		return (NULL);
	buf[i--] = 0;
	if (n < 0)
		buf[0] = '-';
	if (n == 0)
		buf[0] = '0';
	while (n)
	{
		buf[i--] = (char)ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (buf);
}
