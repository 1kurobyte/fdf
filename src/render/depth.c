/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 08:35:39 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 10:30:15 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdint.h>

static void	get_depth(t_fdf *fdf, uint32_t *buf, int32_t idx)
{
	int32_t		i;
	float		z;
	uint8_t		intensity;
	uint32_t	gray;
	float		normalized;

	i = -1;
	while (++i < NUM_THREADS)
	{
		z = fdf->invz_bufs[i][idx];
		z = 1.0f / z;
		if (!isfinite(z))
			intensity = 0;
		else
		{
			normalized = logf(z) / logf(1000.0f);
			normalized = fminf(fmaxf(normalized, 0.0f), 1.0f);
			intensity = (uint8_t)((1.0f - normalized) * 255.0f);
		}
		gray = color_from_rgb(intensity, intensity, intensity);
		if (color_get_r(buf[idx]) < intensity
			&& color_get_g(buf[idx]) < intensity
			&& color_get_b(buf[idx]) < intensity)
			buf[idx] = gray;
	}
}

void	render_depth(t_fdf *fdf)
{
	int32_t		i;
	uint32_t	*buf;

	buf = (uint32_t *)(void *)mlx_get_data_addr(fdf->gfx.frame, &i, &i, &i);
	i = -1;
	while (++i < fdf->window.height * fdf->window.width)
	{
		get_depth(fdf, buf, i);
		if (fdf->rctx.clr_buf[i] != 0)
			buf[i] = fdf->rctx.clr_buf[i];
	}
}
