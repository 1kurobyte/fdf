/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 01:15:02 by smamalig          #+#    #+#             */
/*   Updated: 2025/06/01 12:51:12 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <malloc.h>

void	ft_list_remove_if(t_list **ptr, t_value ref,
	int (*cmp)(t_value, t_value), void (*free_data)(t_value))
{
	t_list	*list;
	t_list	*prev;
	t_list	*temp;

	list = *ptr;
	prev = NULL;
	while (list)
	{
		if (cmp(list->data, ref))
		{
			if (prev)
				prev->next = list->next;
			else
				*ptr = list->next;
			free_data(list->data);
			temp = list;
			list = list->next;
			free(temp);
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
}
