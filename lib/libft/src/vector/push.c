/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:57:44 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:18:23 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	scale_fast(size_t capacity)
{
	return (capacity + (capacity >> 1));
}

t_result	ft_vector_push(t_vector *vec, t_value value)
{
	if (value.type == TYPE_UNDEFINED)
		return (RESULT_OK);
	if (vec->length == vec->capacity
		&& ft_vector_resize(vec, scale_fast(vec->capacity)) != RESULT_OK)
		return (RESULT_ERROR);
	vec->data[(vec->length++ + vec->offset) % vec->capacity] = value;
	return (RESULT_OK);
}
