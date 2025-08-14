/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:25:17 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 10:40:08 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "fdf.h"
#include "vectors.h"

static void	mvt_fwd(t_camera *cam, t_keys *keys, t_mat3f view)
{
	const t_vec3f	fwd = {view.m[2][0], view.m[2][1], view.m[2][2]};

	if (keys->forward)
		cam->pos = (t_vec3f){
			cam->pos.x + fwd.x * MOVE_SPEED,
			cam->pos.y + fwd.y * MOVE_SPEED,
			cam->pos.z + fwd.z * MOVE_SPEED,
		};
	if (keys->backward)
		cam->pos = (t_vec3f){
			cam->pos.x - fwd.x * MOVE_SPEED,
			cam->pos.y - fwd.y * MOVE_SPEED,
			cam->pos.z - fwd.z * MOVE_SPEED,
		};
}

static void	mvt_perp(t_camera *cam, t_keys *keys, t_mat3f view)
{
	const t_vec3f	right = {view.m[0][0], view.m[0][1], view.m[0][2]};

	if (keys->left)
		cam->pos = (t_vec3f){
			cam->pos.x - right.x * MOVE_SPEED,
			cam->pos.y - right.y * MOVE_SPEED,
			cam->pos.z - right.z * MOVE_SPEED,
		};
	if (keys->right)
		cam->pos = (t_vec3f){
			cam->pos.x + right.x * MOVE_SPEED,
			cam->pos.y + right.y * MOVE_SPEED,
			cam->pos.z + right.z * MOVE_SPEED,
		};
}

static void	mvt_vert(t_camera *cam, t_keys *keys, t_mat3f view)
{
	const t_vec3f	up = {view.m[1][0], view.m[1][1], view.m[1][2]};

	if (keys->up)
		cam->pos = (t_vec3f){
			cam->pos.x - up.x * MOVE_SPEED,
			cam->pos.y - up.y * MOVE_SPEED,
			cam->pos.z - up.z * MOVE_SPEED,
		};
	if (keys->down)
		cam->pos = (t_vec3f){
			cam->pos.x + up.x * MOVE_SPEED,
			cam->pos.y + up.y * MOVE_SPEED,
			cam->pos.z + up.z * MOVE_SPEED,
		};
}

void	update_camera_from_keys(t_fdf *fdf)
{
	t_keys		*keys;
	t_camera	*cam;
	t_mat3f		view;

	keys = &fdf->input.keys;
	cam = &fdf->camera;
	update_camera_from_mouse(fdf);
	if (keys->pitch_up)
		cam->rot.x += ROTATION_STEP;
	if (keys->pitch_down)
		cam->rot.x -= ROTATION_STEP;
	if (keys->yaw_left)
		cam->rot.y += ROTATION_STEP;
	if (keys->yaw_right)
		cam->rot.y -= ROTATION_STEP;
	view = get_view_matrix(&fdf->camera);
	mvt_fwd(cam, keys, view);
	mvt_perp(cam, keys, view);
	mvt_vert(cam, keys, view);
}
