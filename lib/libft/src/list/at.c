/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:15 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:29:25 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *list, ssize_t n)
{
	const size_t	size = ft_list_size(list);
	size_t			index;

	if (n >= (ssize_t)size || n < -(ssize_t)size)
		return (NULL);
	index = ((size_t)n) % size;
	while (index-- && list)
		list = list->next;
	return (list);
}
