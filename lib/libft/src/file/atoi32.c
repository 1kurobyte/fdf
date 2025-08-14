/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 08:48:03 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/01 11:41:18 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_internal.h"

static inline _Bool	_ft_file_has_data(t_file *file)
{
	return (file->curr < file->buf + file->len);
}

static t_result	temp(t_file *file, int32_t *ret_ptr, int sign)
{
	_Bool	had_digit;
	int		digit;

	had_digit = false;
	while (_ft_file_has_data(file) && ft_isdigit(*file->curr))
	{
		digit = *file->curr - '0';
		if (*ret_ptr > (INT_MAX - digit) / 10)
			return (RESULT_OVERFLOW);
		*ret_ptr = *ret_ptr * 10 + digit;
		if (_ft_file_advance(file) != RESULT_OK)
			return (RESULT_ERROR);
		had_digit = true;
	}
	if (!had_digit)
		return (RESULT_INVAL);
	*ret_ptr = sign * *ret_ptr;
	_ft_file_skip_whitespace(file);
	return (RESULT_OK);
}

t_result	ft_file_atoi32(t_file *file, int32_t *ret_ptr)
{
	int			sign;
	t_result	result;

	if (ft_file_eof(file))
		return (RESULT_EOF);
	*ret_ptr = 0;
	sign = 1;
	result = _ft_file_skip_whitespace(file);
	if (result != RESULT_OK)
		return (result);
	if (_ft_file_has_data(file) && *file->curr == '-')
	{
		sign = -1;
		if (_ft_file_advance(file))
			return (RESULT_ERROR);
	}
	else if (_ft_file_has_data(file) && *file->curr == '+')
		if (_ft_file_advance(file) != RESULT_OK)
			return (RESULT_ERROR);
	return (temp(file, ret_ptr, sign));
}
