/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:17:34 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/15 10:22:42 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_value	ft_vector_at(t_vector *vec, ssize_t n)
{
	if (n >= (ssize_t)vec->length || n < -(ssize_t)vec->length)
		return (ft_gen_val(TYPE_UNDEFINED, (t_any){0}));
	if (n >= 0)
		return (vec->data[((size_t)n + vec->offset) % vec->capacity]);
	return (vec->data[(vec->length + (size_t)n + vec->offset) % vec->capacity]);
}
