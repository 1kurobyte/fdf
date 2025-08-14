/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foreach.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:50:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/06/01 12:50:27 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list *list, void (*f)(t_value))
{
	while (list)
	{
		f(list->data);
		list = list->next;
	}
}
