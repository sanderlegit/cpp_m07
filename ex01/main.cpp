/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                          e8'   8   '8e          */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:04:31 by averheij      #+#    #+#                 */
/*   Updated: 2021/11/29 13:57:49 by dries               **ee8ee**            */
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

char			rand_char(void) {
	switch (rand() % 3) {
		case 0: return((rand() % (ALPHAUPPERMAX - ALPHAUPPERMIN)) + ALPHAUPPERMIN);
		case 1: return((rand() % (ALPHALOWERMAX - ALPHALOWERMIN)) + ALPHALOWERMIN);
		case 2: return((rand() % (NUMMAX - NUMMIN)) + NUMMIN);
	}
	return 0;
}

std::string		*rand_string(int length) {
	std::string		*str = new std::string();

	for (int i = 0; i < length; i++)
		str->push_back(rand_char());
	return str;
}

int		do_tests(void) {
	int			n[TESTS];
	char		c[TESTS];
	float		f[TESTS];
	std::string	*s[TESTS];

	std::cout << std::endl << "INTS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		n[i] = rand() % 100;
	}
	iter(n, TESTS, print);

	std::cout << std::endl << "CHARS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		c[i] = rand_char();
	}
	iter(c, TESTS, print);

	std::cout << std::endl << "FLOATS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		f[i] = static_cast<float>(rand() % 1000) / 100.0f;
	}
	iter(f, TESTS, print);

	std::cout << std::endl << "STRINGS" << std::endl;
	for (int i = 0; i < TESTS; i++) {
		s[i] = rand_string(8);
	}
	iter(s, TESTS, print);
	std::cout << std::endl;

	for (int i = 0; i < TESTS; i++) {
		delete s[i];
	}

	return (0);
}

int		main(void) {
	srand(time(0));
	do_tests();
	return 0;
}
