/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:38 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 09:26:29 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ui.h"
#include <math.h>
#include <stdint.h>

static inline float	aa_coverage(int32_t x, int32_t y, int32_t r)
{
	const float	d = hypotf((float)x, (float)y);

	if (d <= (float)r - 1.0f)
		return (1.0f);
	if (d >= (float)r + 1.0f)
		return (0.0f);
	return (1.0f - (d - ((float)r - 1.0f)));
}

static inline void	ui_rect_xloop(t_ui_ctx *ui, t_ui_base *rect,
	int32_t dy, int32_t r)
{
	int32_t		dx;
	uint32_t	fill;
	float		alpha;

	dx = -1;
	while (++dx < rect->w)
	{
		alpha = 1.0f;
		if (dx < r && dy < r)
			alpha = aa_coverage(r - 1 - dx, r - 1 - dy, r);
		else if (dx >= rect->w - r && dy < r)
			alpha = aa_coverage(dx - (rect->w - r), r - 1 - dy, r);
		else if (dx < r && dy >= rect->h - r)
			alpha = aa_coverage(r - 1 - dx, dy - (rect->h - r), r);
		else if (dx >= rect->w - r && dy >= rect->h - r)
			alpha = aa_coverage(dx - (rect->w - r), dy - (rect->h - r), r);
		if (alpha <= 0.0f)
			continue ;
		fill = rect->color;
		if (alpha < 1.0f)
			fill = color_lerp(
					ui->get_color(ui->data, rect->x + dx, rect->y + dy),
					rect->color, alpha);
		ui->put_pixel(ui->data, rect->x + dx, rect->y + dy, fill);
	}
}

void	ui_rect(t_ui_ctx *ui, t_ui_base *rect)
{
	int32_t	r;
	int32_t	dy;

	r = rect->border.radius;
	dy = -1;
	while (++dy < rect->h)
		ui_rect_xloop(ui, rect, dy, r);
}
