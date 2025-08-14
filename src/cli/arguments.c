/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 20:49:58 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/01 20:56:18 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "cli.h"

t_result	arguments_init(t_fdf *fdf, int argc, char **argv)
{
	(void)fdf;
	if (argc == 1)
		ft_printf("\tWorldgen not yet implemented\n");
	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (RESULT_ERROR);
	}
	return (RESULT_OK);
}
