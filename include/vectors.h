/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:06:19 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/31 16:43:08 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <stdint.h>

typedef struct s_vec3f
{
	float	x;
	float	y;
	float	z;
}	t_vec3f;

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

typedef struct s_vec2i
{
	int32_t	x;
	int32_t	y;
}	t_vec2i;

typedef struct s_vec3i
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
}	t_vec3i;

typedef struct s_mat3f
{
	float	m[3][3];
}	t_mat3f;

t_mat3f	rotation_x(float a);
t_mat3f	rotation_y(float a);
t_mat3f	rotation_z(float a);
t_mat3f	mat3f_mult(t_mat3f a, t_mat3f b);
t_vec3f	mat3f_vec_mult(t_mat3f m, t_vec3f v);

static inline uint32_t	lerp_channel(uint8_t shift, uint32_t a, uint32_t b,
		float t)
{
	const uint8_t	ca = (a >> shift) & 0xff;
	const uint8_t	cb = (b >> shift) & 0xff;

	return ((ca + (uint32_t)((cb - ca) * t)) << shift);
}

static inline uint32_t	lerp_u32(uint32_t a, uint32_t b, float t)
{
	return (lerp_channel(0, a, b, t)
		| lerp_channel(8, a, b, t)
		| lerp_channel(16, a, b, t));
}

static inline t_vec2i	vec3f_to_2i(t_vec3f v)
{
	return ((t_vec2i){(int32_t)v.x, (int32_t)v.y});
}

static inline t_vec3f	vec3f_sub(t_vec3f a, t_vec3f b)
{
	return ((t_vec3f){
		a.x - b.x,
		a.y - b.y,
		a.z - b.z,
	});
}

static inline t_vec3f	vec3f_add(t_vec3f a, t_vec3f b)
{
	return ((t_vec3f){
		a.x + b.x,
		a.y + b.y,
		a.z + b.z
	});
}

#endif
