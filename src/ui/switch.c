/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:22:49 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 09:20:36 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "vectors.h"
#include <stdbool.h>
#include <stdint.h>

static inline bool	is_inside(int32_t x, int32_t y, int32_t r)
{
	return (x * x + y * y <= r * r);
}

__attribute__((__optnone__))
static bool	is_hovering_switch(t_ui_ctx *ui, t_ui_switch *sw)
{
	const int32_t	mx = (int32_t)ui->get_mouse_x(ui->data);
	const int32_t	my = (int32_t)ui->get_mouse_y(ui->data);
	const int32_t	r = (int32_t)sw->base.border.radius;
	int32_t			dx;
	int32_t			dy;

	if (mx < sw->base.x || mx >= sw->base.x + sw->base.w
		|| my < sw->base.y || my >= sw->base.y + sw->base.h)
		return (false);
	dx = mx - (int32_t)sw->base.x;
	dy = my - (int32_t)sw->base.y;
	if (dx < r && dy < r)
		return (is_inside(r - 1 - dx, r - 1 - dy, r));
	if (dx >= sw->base.w - r && dy < r)
		return (is_inside(dx - (sw->base.w - r), r - 1 - dy, r));
	if (dx < r && dy >= sw->base.h - r)
		return (is_inside(r - 1 - dx, dy - (sw->base.h - r), r));
	if (dx >= sw->base.w - r && dy >= sw->base.h - r)
		return (is_inside(dx - (sw->base.w - r), dy - (sw->base.h - r), r));
	return (true);
}

__attribute__((__optnone__))
static void	draw_switch_knob(t_ui_ctx *ui, t_ui_switch *sw)
{
	t_ui_base	knob;
	int32_t		r;

	r = sw->base.border.radius;
	knob = (t_ui_base){
		.w = (sw->base.h - 4),
		.h = (sw->base.h - 4),
		.x = (int32_t)((float)sw->base.x + 2
			+ sw->anim.state * ((float)sw->base.w - (float)(sw->base.h - 1))),
		.y = (int32_t)((float)sw->base.y + 2),
		.color = lerp_u32(sw->knob.color, sw->knob.active_color,
			sw->anim.state),
		.border = {.radius = r - 2}
	};
	ui_rect(ui, &knob);
}

__attribute__((__optnone__))
void	ui_switch(t_ui_ctx *ui, t_ui_switch *sw)
{
	const bool	hovering = is_hovering_switch(ui, sw);
	const bool	pressed = ui->mouse_pressed(ui->data);
	const bool	just_pressed = pressed && !ui->prev_mouse_down;
	const bool	just_released = !pressed && ui->prev_mouse_down;

	if (just_pressed && hovering)
		sw->clicked = true;
	if (just_released)
	{
		if (sw->clicked && hovering)
			*sw->value = !*sw->value;
		sw->clicked = false;
	}
	sw->anim.state += ((float)*sw->value - sw->anim.state) * sw->anim.velocity;
	sw->base.color = lerp_u32(sw->color, sw->active_color, sw->anim.state);
	ui_rect(ui, &sw->base);
	draw_switch_knob(ui, sw);
}
