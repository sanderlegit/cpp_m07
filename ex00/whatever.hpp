/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 12:04:34 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/28 12:50:50 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template<typename T>
void		swap(T *a, T *b) {
	T	swp;

	swp = *a;
	*a = *b;
	*b = swp;
	return;
}

template<typename T>
T			min(T &a, T &b) {
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T			max(T &a, T &b) {
	if (a > b)
		return a;
	else
		return b;
}

template<typename T>
int			test_swap(T a, T b) {
	T	dupa;
	T	dupb;

	dupa = a;
	dupb = b;
	//std::cout << "swap:\t\ta: " << a << "\tb: " << b << std::endl;
	swap(&a, &b);
	//std::cout << "\t\ta: " << a << "\tb: " << b << std::endl;
	std::cout << "swap:\ta: " << a << "\t\tb: " << b << std::endl;
	if (dupa == b && dupb == a)
		return 0;
	else
		return 1;
}

template<typename T>
int			test_min_max(T a, T b) {
	T	minres;
	T	maxres;

	//std::cout << "min/max:\ta: " << a << "\tb: " << b << std::endl;
	minres = min(a, b);
	maxres = max(a, b);
	if (minres == maxres)
		std::cout << "\tmin:" << minres << "\t=\tmax:" << maxres << std::endl;
	else
		std::cout << "\tmin:" << minres << "\t<\tmax:" << maxres << std::endl;
	if (minres == maxres || minres < maxres)
		return 0;
	else
		return 1;
}

template<typename T>
int		test_both(T a, T b) {
	std::cout << "test:\ta: " << a << "\t\tb: " << b << std::endl;
	if (test_swap(a, b))
		return 1;
	if (test_min_max(a, b))
		return 1;
	return 0;
}

#endif
