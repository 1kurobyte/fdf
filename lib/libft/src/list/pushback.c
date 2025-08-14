/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:41:06 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/22 23:33:31 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pushback(t_list **ptr, t_list *el)
{
	t_list	*list;

	if (!ptr)
		return ;
	list = *ptr;
	if (!list)
	{
		*ptr = el;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = el;
}
