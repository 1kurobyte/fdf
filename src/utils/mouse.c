/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 09:12:47 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:26:08 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdint.h>

int32_t	get_mouse_x(t_render_ctx *ctx)
{
	return (((t_fdf *)ctx->data)->input.mouse.x);
}

int32_t	get_mouse_y(t_render_ctx *ctx)
{
	return (((t_fdf *)ctx->data)->input.mouse.y);
}

int32_t	mouse_pressed(t_render_ctx *ctx)
{
	return (((t_fdf *)ctx->data)->input.mouse.left);
}
