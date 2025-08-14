/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:04:45 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/14 11:19:43 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define _POSIX_C_SOURCE 199309L

# include "options.h"
# include "common.h"
# include "gfx.h"
# include "ui.h"
# include "threads.h"
# include "render.h"
# include "vectors.h"
# include "libft.h"
# include <X11/Xlib.h>
# include <bits/pthreadtypes.h>
# include <stdbool.h>
# include <stdint.h>

# define __USE_MISC
# define __USE_GNU
# include <math.h>

typedef enum e_projection_mode
{
	PROJ_ORTHO,
	PROJ_PERSPECTIVE,
	PROJ_TOPDOWN,
	PROJ_CONIC,
	PROJ_FISHEYE,
	PROJ_SPHERICAL,
	PROJ_STEREOGRAPHIC,
	PROJ_PANINI,
	PROJ_COUNT,
}	t_projection_mode;

typedef struct s_window {
	int32_t	width;
	int32_t	height;
}	t_window;

typedef struct s_mouse {
	int32_t	x;
	int32_t	y;
	int32_t	initial_x;
	int32_t	initial_y;
	int8_t	left;
	int8_t	right;
	int8_t	middle;
	int8_t	scroll;
}	t_mouse;

typedef struct s_keys {
	bool	up;
	bool	down;
	bool	left;
	bool	right;
	bool	forward;
	bool	backward;
	bool	pitch_up;
	bool	pitch_down;
	bool	yaw_left;
	bool	yaw_right;
	bool	roll_left;
	bool	roll_right;
}	t_keys;

typedef struct s_input {
	t_mouse	mouse;
	t_keys	keys;
}	t_input;

typedef struct s_map {
	int32_t	width;
	int32_t	height;
	int32_t	alt_min;
	int32_t	alt_max;
	int32_t	*elevation;
}	t_map;

typedef struct s_camera {
	t_vec3f				rot;
	t_vec3f				pos;
	float				fov;
	float				near;
	float				scale;
	float				height_scale;
	t_projection_mode	mode;
	char				reserved[4];
}	t_camera;

typedef struct s_state {
	uint32_t	color;
	bool		antialiasing;
	bool		face_filling;
	bool		show_depth;
	bool		culling;
}	t_state;

typedef struct s_fdf {
	t_gfx			gfx;
	uint32_t		*clr_bufs[NUM_THREADS];
	float			*invz_bufs[NUM_THREADS];
	t_render_ctx	rctx;
	t_options		opts;
	t_ui_ctx		ui_ctx;
	t_ui_component	ui[MAX_COMPONENTS];
	t_map			map;
	t_window		window;
	t_input			input;
	t_camera		camera;
	t_state			state;
	t_threadpool	pool;
}	t_fdf;

typedef struct s_render_task
{
	t_fdf			*fdf;
	struct s_camera	*cam;
	t_render_ctx	ctx;
	t_mat3f			view;
	float			scale;
	float			height_scale;
	float			x_offset;
	float			y_offset;
	int32_t			min_alt;
	int32_t			max_alt;
	int32_t			row_start;
	int32_t			row_end;
	int32_t			index;
}	t_render_task;

typedef struct s_line
{
	t_vec3f		p0;
	t_vec3f		p1;
	uint32_t	c0;
	uint32_t	c1;
}	t_line;

void		cycle_projection_up(t_fdf *fdf);
void		cycle_projection_down(t_fdf *fdf);

void		render_depth(t_fdf *fdf);
void		merge_framebuffers(t_fdf *fdf);
void		clear_framebuffers(t_fdf *fdf);
t_result	framebuffers_init(t_fdf *fdf);

t_result	init_font(t_fdf *fdf);
void		render_text(t_fdf *fdf, t_vec2f pos, const char *text,
				uint32_t color);
void		display_projection_type(t_fdf *fdf);
t_vec3f		project_point(t_fdf *fdf, t_render_task *task, int i, int j);

void		ui_init(t_fdf *fdf);
void		ui_render(t_fdf *fdf);
void		draw_gimbal(t_fdf *fdf);

void		init_tasks(t_fdf *fdf, t_render_task *tasks);
void		render_task(void *arg);
void		render_lines(t_fdf *fdf, t_render_task *task, int i, int j);
void		render_faces(t_fdf *fdf, t_render_task *task, int i, int j);

int			fdf_destroy(t_fdf *fdf);

void		put_pixel_ui(
				t_render_ctx *ctx, int32_t x, int32_t y, uint32_t color);
uint32_t	get_color(t_render_ctx *ctx, int32_t x, int32_t y);
int32_t		get_mouse_x(t_render_ctx *ctx);
int32_t		get_mouse_y(t_render_ctx *ctx);
int32_t		mouse_pressed(t_render_ctx *ctx);

int			register_mouse_hooks(t_fdf *fdf);
int			register_key_hooks(t_fdf *fdf);
int			register_hooks(t_fdf *fdf);

static inline float	fpart(float x)
{
	return (x - floorf(x));
}

static inline float	rfpart(float x)
{
	return (1.f - fpart(x));
}

static inline void	swapf(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static inline t_mat3f	get_view_matrix(t_camera *cam)
{
	return (mat3f_mult(rotation_x(-cam->rot.x),
			rotation_y(-cam->rot.y)));
}

#endif
