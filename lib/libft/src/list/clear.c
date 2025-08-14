/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:47:59 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/02 20:23:04 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_clear(t_list **ptr, void (*del)(t_value))
{
	if (!ptr)
		return ;
	while (*ptr)
	{
		auto t_list * temp = *ptr;
		*ptr = temp->next;
		if (temp->data.type != TYPE_UNDEFINED)
			del(temp->data);
		free(temp);
	}
}
