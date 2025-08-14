/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:16:32 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 16:55:11 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/X.h>

int	register_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->gfx.win, DestroyNotify, 0, fdf_destroy, fdf);
	register_key_hooks(fdf);
	register_mouse_hooks(fdf);
	return (0);
}
