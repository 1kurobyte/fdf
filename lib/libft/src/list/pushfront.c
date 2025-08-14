/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:38:45 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/22 23:33:45 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_pushfront(t_list **ptr, t_list *el)
{
	if (!ptr)
		return ;
	if (*ptr)
		el->next = *ptr;
	*ptr = el;
}
