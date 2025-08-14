/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:13:43 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:14:06 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "options.h"

t_result	options_init(t_options *opt)
{
	opt->width = 1200;
	opt->height = 800;
	return (RESULT_OK);
}
