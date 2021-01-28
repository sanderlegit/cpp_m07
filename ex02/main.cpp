/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 15:30:07 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/28 17:47:06 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h> //rand
#include <time.h>	//time
#include "Array.hpp"

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

template<typename T>
T			safe_idx(unsigned int idx, Array<T> &arr) {
	T	tmp;

	try {
		tmp = arr[idx];
		std::cout << "idx " << idx << ":\t" << tmp << std::endl;
	} catch (std::exception &e) {
		std::cout << "idx " << idx << " is out of range." << std::endl;
	}
	return tmp;
}

template<typename T>
void		test_empty_arr(void) {
	Array<T>	*arr = new Array<T>();

	std::cout << std::endl << "Empty array" << std::endl;
	std::cout << "size:" << arr->size() << std::endl;
	safe_idx(0, *arr);
}

template<typename T>
void		test_arr(void) {
	int			size = 20;
	Array<T>	*arr = new Array<T>(20);
	Array<T>	*arr2 = new Array<T>();
	Array<T>	*arr3 = 0;

	std::cout << std::endl << "size " << size << " array" << std::endl;
	std::cout << "size:" << arr->size() << std::endl;
	for (int i = 0; i < size; i++)
		safe_idx(i, *arr);
	for (int i = 0; i < size; i++)
		(*arr)[i] = static_cast<T>(rand() % 10000) / 100;
	*arr2 = *arr;
	arr3 = new Array<T>(*arr);
	std::cout << "arr:\t" << arr << std::endl;
	std::cout << "arr2:\t" << arr2 << std::endl;
	std::cout << "arr3:\t" << arr3 << std::endl;
	for (int i = 0; i < size; i++) {
		try {
			std::cout << "idx " << i << "\tarr:\t" << (*arr)[i] << std::endl;
			std::cout << "\tarr2:\t" << (*arr2)[i] << std::endl;
			std::cout << "\tarr3:\t" << (*arr3)[i] << std::endl;
		} catch (std::exception &e) {
			std::cout << "idx " << i << " is out of range." << std::endl;
		}
	}
	delete arr;
	delete arr2;
	delete arr3;
}

template<>
void		test_arr<std::string *>(void) {
	int						size = 20;
	Array<std::string *>	*arr = new Array<std::string *>(20);
	Array<std::string *>	*arr2 = new Array<std::string *>();
	Array<std::string *>	*arr3 = 0;

	std::cout << std::endl << "size " << size << " array" << std::endl;
	std::cout << "size:" << arr->size() << std::endl;
	for (int i = 0; i < size; i++)
		safe_idx(i, *arr);
	for (int i = 0; i < size; i++) {
		(*arr)[i] = rand_string(10);
	}
	*arr2 = *arr;
	arr3 = new Array<std::string *>(*arr);
	std::cout << "arr:\t" << arr << std::endl;
	std::cout << "arr2:\t" << arr2 << std::endl;
	std::cout << "arr3:\t" << arr3 << std::endl;
	for (int i = 0; i < size; i++) {
		try {
			std::cout << "idx " << i << "\tarr:\t" << *(*arr)[i] << std::endl;
			std::cout << "\tarr2:\t" << *(*arr2)[i] << std::endl;
			std::cout << "\tarr3:\t" << *(*arr3)[i] << std::endl;
		} catch (std::exception &e) {
			std::cout << "idx " << i << " is out of range." << std::endl;
		}
	}
	for (int i = 0; i < size; i++) {
		delete (*arr)[i];
	}
	delete arr;
	delete arr2;
	delete arr3;
}

int 		main(void)
{
	srand(time(0));
	std::cout << std::endl << "----INTS----" << std::endl;
	test_empty_arr<int>();
	test_arr<int>();
	std::cout << std::endl << "----FLOATS----" << std::endl;
	test_empty_arr<float>();
	test_arr<float>();
	std::cout << std::endl << "----DOUBLES----" << std::endl;
	test_empty_arr<double>();
	test_arr<double>();
	std::cout << std::endl << "----STRINGS----" << std::endl;
	test_empty_arr<std::string>();
	test_arr<std::string *>();
	return 0;
}
