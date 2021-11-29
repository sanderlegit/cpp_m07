/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                          e8'   8   '8e          */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 13:34:06 by averheij      #+#    #+#                 */
/*   Updated: 2021/11/29 13:59:36 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T>
void		iter(T *arr, unsigned long const len, void (*f)(T)) {
	for (unsigned long i = 0; i < len; i++) {
		f(arr[i]);
	}
	return;
}

template<typename T>
void		print(T val) {
	std::cout << val << " ";
}

template<>
void		print<std::string *>(std::string * val) {
	std::cout << val->c_str() << " ";
}

#endif
