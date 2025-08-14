/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:38:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:08:20 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "libft.h"
#include "mlx.h"
#include "options.h"

t_result	gfx_init(t_gfx *gfx, t_options opt)
{
	int	_;

	gfx->mlx = mlx_init();
	if (!gfx->mlx)
		return (RESULT_ERROR);
	gfx->frame = mlx_new_image(gfx->mlx, opt.width, opt.height);
	if (!gfx->frame)
		return (gfx_destroy(gfx), RESULT_ERROR);
	gfx->font = mlx_xpm_file_to_image(gfx->mlx,
			(char *)(intptr_t)"assets/font.xpm", &_, &_);
	if (!gfx->font)
		return (gfx_destroy(gfx), RESULT_ERROR);
	gfx->win = mlx_new_window(gfx->mlx, opt.width, opt.height,
			(char *)(intptr_t)"FdF");
	if (!gfx->win)
		return (gfx_destroy(gfx), RESULT_ERROR);
	return (RESULT_OK);
}
