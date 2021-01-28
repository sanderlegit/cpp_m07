/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:04:31 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/28 12:50:12 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <time.h>
#include <stdlib.h>

#define TESTS 10

int		do_tests(void) {
	std::cout << std::endl << "\t\tINTS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		if (test_both<int>(static_cast<int>(rand() % 500), static_cast<int>(rand() % 500)))
			return 1;
	}
	if (test_both<int>(static_cast<int>(50), static_cast<int>(50)))
			return 1;
	std::cout << std::endl << "\t\tFLOATS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		if (test_both<float>(static_cast<float>(rand() % 50000) / 100, static_cast<float>(rand() % 50000) / 100))
			return 1;
	}
	if (test_both<float>(static_cast<float>(30008) / 100, static_cast<float>(30008) / 100))
		return 1;
	std::cout << std::endl << "\t\tDOUBLES" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		if (test_both<double>(static_cast<double>(rand() % 50000) / 100, static_cast<double>(rand() % 50000) / 100))
			return 1;
	}
	if (test_both<double>(static_cast<double>(50001) / 100, static_cast<double>(50001) / 100))
		return 1;
	std::cout << std::endl << "\t\tBOOLS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		if (test_both<bool>(static_cast<bool>(rand() % 2), static_cast<bool>(rand() % 2)))
			return 1;
	}
	std::cout << std::endl << "\t\tCHARS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		if (test_both<char>(static_cast<char>(rand() % 150) + 55, static_cast<char>(rand() % 150) + 55))
			return 1;
	}
	if (test_both<char>(static_cast<char>(100), static_cast<char>(100)))
		return 1;
	return (0);
}

int		main(void) {
	if (do_tests())
		std::cout << "Oh no, a test failed. :(" << std::endl;
	else
		std::cout << "Yay, all passed! :)" << std::endl;
	return (0);
}
