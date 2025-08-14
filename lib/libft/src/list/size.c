/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:33:28 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/27 12:26:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_size(t_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}
