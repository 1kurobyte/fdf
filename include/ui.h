/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 12:13:07 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:11:15 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include <stdbool.h>
# include <stdint.h>

typedef void		(*t_ui_put_pixel_fn)(void *data, int32_t x, int32_t y,
									uint32_t color);
typedef uint32_t	(*t_ui_get_color_fn)(void *data, int32_t x, int32_t y);
typedef int32_t		(*t_ui_generic_fn)(void *data);

typedef struct s_ui_ctx
{
	t_ui_put_pixel_fn	put_pixel;
	t_ui_generic_fn		get_mouse_x;
	t_ui_generic_fn		get_mouse_y;
	t_ui_get_color_fn	get_color;
	t_ui_generic_fn		mouse_pressed;
	void				*data;
	bool				prev_mouse_down;
	char				reserved[7];
}	t_ui_ctx;

typedef enum e_ui_component_type
{
	UI_COMPONENT_NONE,
	UI_COMPONENT_RECT,
	UI_COMPONENT_SWITCH,
	UI_COMPONENT_SLIDER,
	UI_COMPONENT_TEXT,
	UI_COMPONENT_INPUT,
	UI_COMPONENT_BUTTON,
	UI_COMPONENT_COLOR_PICKER,
}	t_ui_coponent_type;

typedef struct s_ui_base
{
	int32_t		x;
	int32_t		y;
	int32_t		w;
	int32_t		h;
	uint32_t	color;
	struct s_border_properties
	{
		int32_t		radius;
		int32_t		width;
		uint32_t	color;
	}	border;
}	t_ui_base;

typedef struct s_ui_animation
{
	float	state;
	float	velocity;
}	t_ui_animation;

typedef t_ui_base	t_ui_rect;

typedef struct s_ui_switch
{
	bool			*value;
	t_ui_base		base;
	t_ui_animation	anim;
	uint32_t		color;
	uint32_t		active_color;
	struct s_ui_switch_knob
	{
		uint32_t	color;
		uint32_t	active_color;
	}	knob;
	bool			clicked;
	char			reserved[7];
}	t_ui_switch;

typedef struct s_ui_slider
{
	t_ui_base	base;
	int32_t		min_value;
	int32_t		max_value;
	int32_t		current_value;
	uint32_t	slider_color;
}	t_ui_slider;

typedef struct s_ui_text
{
	t_ui_base	base;
	uint32_t	text_color;
	int32_t		font_size;
	const char	*text;
}	t_ui_text;

typedef struct s_ui_input
{
	t_ui_base	base;
	int32_t		cursor_pos;
	uint32_t	input_color;
	char		*value;
}	t_ui_input;

typedef struct s_ui_button
{
	t_ui_base	base;
	uint32_t	color;
	char		reserved[4];
	bool		*pressed;
}	t_ui_button;

typedef struct s_ui_color_picker
{
	t_ui_base	base;
	uint32_t	*value;
	float		hue;
	float		saturation;
	float		value_v;
	float		triangle_cx;
	float		triangle_cy;
	char		reserved[4];
}	t_ui_color_picker;

typedef struct s_ui_component
{
	t_ui_coponent_type	type;
	char				reserved[4];
	union	u_component_as
	{
		t_ui_rect			rect;
		t_ui_switch			switch_;
		t_ui_slider			slider;
		t_ui_text			text;
		t_ui_input			input;
		t_ui_button			button;
		t_ui_color_picker	color_picker;
	}	as;
}	t_ui_component;

void	ui_switch(t_ui_ctx *ctx, t_ui_switch *sw);
void	ui_rect(t_ui_ctx *ctx, t_ui_rect *rect);
void	ui_slider(t_ui_ctx *ctx, t_ui_slider *slider);
void	ui_text(t_ui_ctx *ctx, t_ui_text *text);
void	ui_input(t_ui_ctx *ctx, t_ui_input *input);
void	ui_button(t_ui_ctx *ctx, t_ui_button *button);
void	ui_color_picker(t_ui_ctx *ctx, t_ui_color_picker *cp);

#endif
