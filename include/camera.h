/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:23:50 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/13 10:24:28 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "fdf.h"

void	update_camera_from_mouse(t_fdf *fdf);
void	update_camera_from_keys(t_fdf *fdf);

#endif
