/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:04:31 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/28 14:22:09 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <stdlib.h> //rand
#include <time.h>	//time

#define TESTS 10

#define ALPHAUPPERMAX	90
#define ALPHAUPPERMIN	65
#define ALPHALOWERMAX	122
#define ALPHALOWERMIN	97
#define NUMMAX	57
#define NUMMIN	48

std::string		*rand_string(int length) {
	std::string		*str = new std::string();

	for (int i = 0; i < length; i++) {
		switch (rand() % 3) {
			case 0: str->push_back((rand() % (ALPHAUPPERMAX - ALPHAUPPERMIN)) + ALPHAUPPERMIN);
					break;
			case 1: str->push_back((rand() % (ALPHALOWERMAX - ALPHALOWERMIN)) + ALPHALOWERMIN);
					break;
			case 2: str->push_back((rand() % (NUMMAX - NUMMIN)) + NUMMIN);
					break;
		}
	}
	return str;
}

int		do_tests(void) {
	int			n[TESTS];
	char		c[TESTS];
	float		f[TESTS];
	std::string	*s[TESTS];

	std::cout << std::endl << "\t\tINTS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		n[i] = rand() % 100;
	}
	iter(n, TESTS, print<int>);

	std::cout << std::endl << "\t\tCHARS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		c[i] = rand() % 20 + 90;
	}
	iter(c, TESTS, print<char>);

	std::cout << std::endl << "\t\tFLOATS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		f[i] = static_cast<float>(rand() % 1000) / 100.0f;
	}
	iter(f, TESTS, &print<float>);

	std::cout << std::endl << "\t\tSTRINGS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		s[i] = rand_string(8);
	}
	iter(s, TESTS, print<std::string *>);
	std::cout << std::endl;

	return (0);
}

int		main(void) {
	srand(time(0));
	do_tests();
	return 0;
}
