/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   framebuffers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 08:59:09 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:44:29 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stddef.h>
#include <stdint.h>

t_result	framebuffers_init(t_fdf *fdf)
{
	uint32_t	*clr_buf;
	float		*invz_buf;
	int32_t		i;
	size_t		size;

	i = -1;
	size = (size_t)fdf->window.width * (size_t)fdf->window.height;
	while (++i < NUM_THREADS)
	{
		fdf->clr_bufs[i] = ft_calloc(size, sizeof(uint32_t));
		fdf->invz_bufs[i] = ft_calloc(size, sizeof(float));
		if (!fdf->clr_bufs[i] || !fdf->invz_bufs[i])
			return (RESULT_ERROR);
	}
	clr_buf = ft_calloc(size, sizeof(uint32_t));
	invz_buf = ft_calloc(size, sizeof(float));
	if (!clr_buf || !invz_buf)
		return (RESULT_ERROR);
	fdf->rctx = (t_render_ctx){
		.width = fdf->window.width,
		.height = fdf->window.height,
		.data = fdf,
		.clr_buf = clr_buf,
		.invz_buf = invz_buf};
	return (RESULT_OK);
}

void	merge_framebuffers(t_fdf *fdf)
{
	int32_t		i;
	int32_t		idx;
	uint32_t	*buf;
	float		best_depth;
	uint32_t	color;

	buf = (uint32_t *)(void *)mlx_get_data_addr(fdf->gfx.frame, &i, &i, &i);
	idx = -1;
	while (++idx < fdf->window.width * fdf->window.height)
	{
		best_depth = 0.0f;
		color = 0;
		i = -1;
		while (++i < NUM_THREADS)
		{
			if (fdf->invz_bufs[i][idx] > best_depth)
			{
				best_depth = fdf->invz_bufs[i][idx];
				color = fdf->clr_bufs[i][idx];
			}
		}
		buf[idx] = color_blend(color, buf[idx]);
		if (fdf->rctx.clr_buf[idx] != 0)
			buf[idx] = fdf->rctx.clr_buf[idx];
	}
}

void	clear_framebuffers(t_fdf *fdf)
{
	int32_t		i;
	size_t		size;
	uint32_t	*buf;

	size = (size_t)fdf->window.width * (size_t)fdf->window.height;
	buf = (uint32_t *)(void *)mlx_get_data_addr(fdf->gfx.frame, &i, &i, &i);
	ft_memset(buf, 0, size * sizeof(uint32_t));
	i = -1;
	while (++i < NUM_THREADS)
	{
		ft_memset(fdf->clr_bufs[i], 0, size * sizeof(uint32_t));
		ft_memset(fdf->invz_bufs[i], 0, size * sizeof(float));
	}
	ft_memset(fdf->rctx.clr_buf, 0, size * sizeof(uint32_t));
	ft_memset(fdf->rctx.invz_buf, 0, size * sizeof(float));
}
