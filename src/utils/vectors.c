/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:36:32 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 16:53:41 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <math.h>

t_mat3f	rotation_x(float a)
{
	const float	c = cosf(a);
	const float	s = sinf(a);

	return ((t_mat3f){{{1, 0, 0}, {0, c, -s}, {0, s, c}}});
}

t_mat3f	rotation_y(float a)
{
	const float	c = cosf(a);
	const float	s = sinf(a);

	return ((t_mat3f){{{c, 0, s}, {0, 1, 0}, {-s, 0, c}}});
}

__attribute__((__unused__))
t_mat3f	rotation_z(float a)
{
	const float	c = cosf(a);
	const float	s = sinf(a);

	return ((t_mat3f){{{c, -s, 0}, {s, c, 0}, {0, 0, 1}}});
}

t_mat3f	mat3f_mult(t_mat3f a, t_mat3f b)
{
	t_mat3f	m;
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m.m[i][j] = a.m[i][0] * b.m[0][j]
				+ a.m[i][1] * b.m[1][j]
				+ a.m[i][2] * b.m[2][j];
	}
	return (m);
}

t_vec3f	mat3f_vec_mult(t_mat3f m, t_vec3f v)
{
	return ((t_vec3f){
		m.m[0][0] * v.x + m.m[0][1] * v.y + m.m[0][2] * v.z,
		m.m[1][0] * v.x + m.m[1][1] * v.y + m.m[1][2] * v.z,
		m.m[2][0] * v.x + m.m[2][1] * v.y + m.m[2][2] * v.z
	});
}
