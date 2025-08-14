/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unshift.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:09:24 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:17:52 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// fast multiply by 1.5
static inline size_t	scale_fast(size_t capacity)
{
	return (capacity + (capacity >> 1));
}

t_result	ft_vector_unshift(t_vector *vec, t_value value)
{
	if (value.type == TYPE_UNDEFINED)
		return (RESULT_OK);
	if (vec->length == vec->capacity
		&& ft_vector_resize(vec, scale_fast(vec->capacity)) != RESULT_OK)
		return (RESULT_ERROR);
	vec->length++;
	vec->offset--;
	if (vec->offset == -1UL)
		vec->offset = vec->capacity - 1;
	vec->data[vec->offset % vec->capacity] = value;
	return (RESULT_OK);
}
