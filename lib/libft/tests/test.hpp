/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                              ⠀⠀⠀⠀⢀⣴⣿⠟⠁ ⣿⠟⢹⣿⣿⠀   */
/*                                                    +:+ +:+         +:+     */
/*   By: ms <smamalig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:29:03 by ms                #+#    #+#             */
/*   Updated: 2025/06/04 15:45:55 by smamalig              ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

#include <cstring>
#include <vector>
#include <iostream>

extern void test_alloc();
extern void test_checks();
extern void test_convert();
extern void test_io();
extern void test_list();
extern void test_math();
extern void test_mem();
extern void test_str_compare();
extern void test_str_concat();
extern void test_str_copy();
extern void test_str_info();
extern void test_str_modify();
extern void test_str_search();
extern void test_vector();

enum ResultType {
	RESULT_EQ,
	RESULT_NEQ,
	RESULT_LT,
	RESULT_GT,
};

template <typename T, typename K>
struct ExpectResult {
	ResultType	type;
	bool		error{false};
	T			expected{0};
	T			got{0};
	K			info{0};
};

template <typename T, typename K>
using ExpectResults = std::vector<ExpectResult<T, K>>;

template <typename T, typename K>
extern void test(const char *desc, void (*test_fn)(ExpectResults<T, K>&))
{
	ExpectResults<T, K> res;
	test_fn(res);
	if (!res.size()) {
		std::cout << "\t\x1b[92m✔\x1b[0m " << desc << "\n";
		return;
	}
	std::cout << "\t\x1b[91m✘\x1b[0m " << desc << "\n";
	for (const auto x : res)
		std::cout << "\t\t`" << x.info << "`: expected `" << x.expected << "`, got `" << x.got << "`\n";
}

template <typename K>
extern ExpectResult<char *, K> expect_str_eq(char *expected, char *got, K info) {
	ExpectResult<char *, K> res;
	if (strcmp(expected, got) == 0)
		return res;
	res.info = info;
	res.expected = expected;
	res.got = got;
	res.error = true;
	return res;
}

template <typename T, typename K>
extern ExpectResult<T, K> expect_eq(T expected, T got, K info) {
	ExpectResult<T, K> res;
	if (expected == got)
		return res;
	res.info = info;
	res.expected = expected;
	res.got = got;
	res.error = true;
	return res;
}

template <typename T, typename K>
extern ExpectResult<T, K> expect_neq(T expected, T got, K info) {
	ExpectResult<T, K> res;
	if (expected != got)
		return res;
	res.info = info;
	res.expected = expected;
	res.got = got;
	res.error = true;
	return res;
}

extern void describe(const char *);

#endif
