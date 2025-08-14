/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:26:30 by smamalig          #+#    #+#             */
/*   Updated: 2025/02/27 16:22:15 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
extern "C" {
#include "libft.h"
}

void test_list() {
	describe("list");
	test<char *, const char *>("at", [](auto res){
		t_list *list = ft_list_new((void *)"Hello");
		if (!list) return;
		list->next = ft_list_new((void *)"World");
		if (!list->next) return;
		list->next->next = ft_list_new((void *)"!!!");
		if (!list->next->next) return;
		list->next->next->next = ft_list_new((void *)"OK");
		if (!list->next->next->next) return;

		t_list *at = ft_list_at(list, -3);
		ExpectResult expect1 = expect_str_eq((char *)"World", (char *)at->data, "test1");
		if (expect1.error)
			res.push_back(expect1);
	});
}
