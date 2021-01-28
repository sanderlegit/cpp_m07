/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 13:34:06 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/28 14:21:44 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

//template<typename T>
//void		iter(T *arr, unsigned long const len, T (*f)(T)) {
	//for (unsigned long i = 0; i < len; i++) {
		//arr[i] = f(arr[i]);
	//}
	//return;
//}

template<typename T, typename F>
void		iter(T *arr, unsigned long const len, F f) {
	for (unsigned long i = 0; i < len; i++) {
		f(arr[i]);
	}
	return;
}

template<typename T>
void		print(T &val) {
	std::cout << val << " ";
}

template<>
void		print<std::string *>(std::string *&val) {
	std::cout << val->c_str() << " ";
}


//template<typename T>
//T			addone(T &val) {
	//std::cout << val + 1 << " was +1"<< std::endl;
	//return (val + 1);
//}


#endif
