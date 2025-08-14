/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:52:10 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 10:13:30 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <asm-generic/errno.h>
#include <errno.h>
#include <stddef.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if ((size != 0) && (n > SIZE_MAX / size))
	{
		errno = EOVERFLOW;
		return (NULL);
	}
	ptr = ft_malloc(n * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, n * size);
	return (ptr);
}
