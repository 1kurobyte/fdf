/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:50:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/06/01 12:48:06 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_map(t_list *list, t_value (*f)(t_value))
{
	t_list	*new;
	t_list	*ref;

	if (!list)
		return (NULL);
	new = ft_list_new(f(list->data));
	ref = new;
	list = list->next;
	while (list)
	{
		ref->next = ft_list_new(f(list->data));
		ref = ref->next;
		list = list->next;
	}
	return (new);
}
