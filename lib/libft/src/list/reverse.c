/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:20:48 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/26 20:20:56 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_reverse(t_list **ptr)
{
	t_list	*temp;
	t_list	*list;
	t_list	*prev;

	prev = NULL;
	if (!ptr)
		return ;
	list = *ptr;
	while (list)
	{
		temp = list->next;
		list->next = prev;
		prev = list;
		list = temp;
	}
	*ptr = prev;
}
