/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:42:14 by smamalig          #+#    #+#             */
/*   Updated: 2025/04/16 22:54:04 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include <stdint.h>

int	ft_vsprintf(char *dst, const char *fmt, va_list ap)
{
	return (ft_vsnprintf(dst, SIZE_MAX, fmt, ap));
}
