/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:14:09 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/27 16:17:01 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
extern "C" {
#include "libft.h"
}

void test_io() {
	describe("input / output");
	test<int, int>("putchar_fd", [](auto res) {
		(void)res;
		ft_putchar_fd('c', 1);
	});
	test<int, int>("putstr_fd", [](auto res) {
		(void)res;
		ft_putstr_fd("str", 1);
	});
	test<int, int>("putendl_fd", [](auto res) {
		(void)res;
		ft_putendl_fd("endl", 1);
	});
	test<int, int>("putnbr_fd", [](auto res) {
		(void)res;
		ft_putnbr_fd(123123123, 1);
	});
}
