/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:37:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/12 13:52:35 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*alloc;

	if (!ptr)
		return (ft_malloc(new_size));
	if (new_size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	alloc = ft_malloc(new_size);
	if (!alloc)
		return (NULL);
	if (new_size <= old_size)
		ft_mempcpy(alloc, ptr, new_size);
	else
		ft_mempcpy(alloc, ptr, old_size);
	ft_free(ptr);
	return (alloc);
}
