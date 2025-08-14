/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:03:34 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:14:25 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include "libft.h"
# include <stdint.h>

typedef struct s_options
{
	int32_t	width;
	int32_t	height;
}	t_options;

t_result	options_init(t_options *opt);
void		options_destroy(t_options *opt);

#endif
