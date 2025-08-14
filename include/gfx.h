/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 13:38:11 by smamalig          #+#    #+#             */
/*   Updated: 2025/08/02 14:04:23 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# include "libft.h"
# include "options.h"

typedef struct s_gfx
{
	void	*mlx;
	void	*win;
	void	*font;
	void	*frame;
}	t_gfx;

t_result	gfx_init(t_gfx *gfx, t_options opt);
void		gfx_destroy(t_gfx *gfx);

#endif
