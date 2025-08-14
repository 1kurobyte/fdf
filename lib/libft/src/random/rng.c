/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rng.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:37 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/17 13:45:03 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline uint64_t	rol64(uint64_t x, int k)
{
	return ((x << k) | (x >> (64 - k)));
}

uint64_t	ft_rng_u64(t_rng256 *rng)
{
	auto uint64_t * s = rng->s;
	auto uint64_t x = rol64(s[0] + s[3], 23) + s[0];
	auto uint64_t t = rng->s[1] << 17;
	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];
	s[2] ^= t;
	s[3] = rol64(s[3], 45);
	return (x);
}

uint32_t	ft_rng_u32(t_rng256 *rng)
{
	return ((uint32_t)(ft_rng_u64(rng) >> 32));
}

double	ft_rng_f64(t_rng256 *rng)
{
	return ((double)(ft_rng_u64(rng) >> 11) *(1.0 / 9007199254740992.0));
}
