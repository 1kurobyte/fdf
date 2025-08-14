/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:49:14 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:39:07 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ui.h"
#include "fdf.h"
#include <stdint.h>

#define ACTIVE_COLOR 0x102010u

static void	push_component(t_fdf *fdf, t_ui_component comp)
{
	static int	index = 0;

	fdf->ui[index++] = comp;
}

__attribute__((__always_inline__))
static inline void	ui_init_2(t_fdf *fdf)
{
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_SWITCH,
		.as.switch_ = {.color = 0x808080u, .value = &fdf->state.face_filling,
		.base = {.x = 16, .y = 48, .w = 48, .h = 24, .border = {.radius = 8}},
		.anim = {0, ANIMATION_SPEED}, .active_color = 0x00ff00u,
		.knob = {.color = 0xffffffu, .active_color = ACTIVE_COLOR}}});
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_SWITCH,
		.as.switch_ = {.color = 0x808080u, .value = &fdf->state.show_depth,
		.base = {.x = 16, .y = 80, .w = 48, .h = 24, .border = {.radius = 8}},
		.anim = {0, ANIMATION_SPEED}, .active_color = 0x00ff00u,
		.knob = {.color = 0xffffffu, .active_color = ACTIVE_COLOR}}});
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_SWITCH,
		.as.switch_ = {.color = 0x808080u, .value = &fdf->state.culling,
		.base = {.x = 16, .y = 112, .w = 48, .h = 24, .border = {.radius = 8}},
		.anim = {0, ANIMATION_SPEED}, .active_color = 0x00ff00u,
		.knob = {.color = 0xffffffu, .active_color = ACTIVE_COLOR}}});
}

void	ui_init(t_fdf *fdf)
{
	fdf->ui_ctx = (t_ui_ctx){
		.data = &fdf->rctx,
		.put_pixel = (t_ui_put_pixel_fn)put_pixel_ui,
		.get_mouse_x = (t_ui_generic_fn)get_mouse_x,
		.get_mouse_y = (t_ui_generic_fn)get_mouse_y,
		.get_color = (t_ui_get_color_fn)get_color,
		.mouse_pressed = (t_ui_generic_fn)mouse_pressed,
	};
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_RECT,
		.as.rect = {.x = 500, .y = 16, .w = 200, .h = 24,
		.color = ACTIVE_COLOR, .border = {.radius = 8}}});
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_RECT,
		.as.rect = {.x = 12, .y = 12, .w = 200, .h = 160,
		.color = ACTIVE_COLOR, .border = {.radius = 8}}});
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_RECT,
		.as.rect = {.x = 1100, .y = 0, .w = 100, .h = 100,
		.color = ACTIVE_COLOR, .border = {.radius = 50}}});
	push_component(fdf, (t_ui_component){.type = UI_COMPONENT_SWITCH,
		.as.switch_ = {.color = 0x808080u, .value = &fdf->state.antialiasing,
		.base = {.x = 16, .y = 16, .w = 48, .h = 24, .border = {.radius = 8}},
		.anim = {0, ANIMATION_SPEED}, .active_color = 0x00ff00u,
		.knob = {.color = 0xffffffu, .active_color = ACTIVE_COLOR}}});
	ui_init_2(fdf);
}

void	ui_render(t_fdf *fdf)
{
	int32_t	i;
	char	buffer[128];

	i = -1;
	while (++i < MAX_COMPONENTS)
	{
		if (fdf->ui[i].type == UI_COMPONENT_NONE)
			continue ;
		if (fdf->ui[i].type == UI_COMPONENT_RECT)
			ui_rect(&fdf->ui_ctx, &fdf->ui[i].as.rect);
		if (fdf->ui[i].type == UI_COMPONENT_SWITCH)
			ui_switch(&fdf->ui_ctx, &fdf->ui[i].as.switch_);
	}
	render_text(fdf, (t_vec2f){64.0f, 16.0f}, "Antialiasing", 0x00ff00);
	render_text(fdf, (t_vec2f){64.0f, 48.0f}, "Face Filling", 0x00ff00);
	render_text(fdf, (t_vec2f){64.0f, 80.0f}, "Show Depth", 0x00ff00);
	render_text(fdf, (t_vec2f){64.0f, 112.0f}, "Culling", 0x00ff00);
	ft_snprintf(buffer, 128, "Scale: %i.%03i", (int)fdf->camera.scale,
		(int)(fpart(fdf->camera.scale) * 1000.0f));
	render_text(fdf, (t_vec2f){16.0f, 144.0f}, buffer, 0x00ff00);
	fdf->ui_ctx.prev_mouse_down = fdf->input.mouse.left;
}
