/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:56:47 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 13:59:22 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include "mlx.h"

void	gfx_destroy(t_gfx *gfx)
{
	if (!gfx->mlx)
		return ;
	if (gfx->font)
		mlx_destroy_image(gfx->mlx, gfx->font);
	if (gfx->frame)
		mlx_destroy_image(gfx->mlx, gfx->frame);
	if (gfx->win)
		mlx_destroy_window(gfx->mlx, gfx->win);
	mlx_destroy_display(gfx->mlx);
	free(gfx->mlx);
}
