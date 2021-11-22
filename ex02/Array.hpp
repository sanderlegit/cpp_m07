/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                         e8'   8   '8e          */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 15:54:19 by averheij      #+#    #+#                 */
/*   Updated: 2021/11/22 16:38:11 by dries               **ee8ee**            */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <stddef.h>
#include <exception>
#include <iostream>

template<typename T>
class Array {
	public:
		Array<T>(void) : _arr(new T[0]), _len(0) {
			return;
		}

		Array<T>(unsigned int len) : _arr(new T[len]), _len(len) {
			for (unsigned int i = 0; i < len; i++) {
				_arr[i] = static_cast<T>(0);
			}
			return;
		}

		Array<T>(Array<T> const &src) : _arr(NULL), _len(0) {
			*this = src;
			return;
		}

		~Array<T>(void) {
			delete[] _arr;
			return;
		}

		unsigned int	size(void) const {
			return _len;
		}

		T				&operator[](unsigned int const idx) {
			if (idx >= _len)
				throw std::exception();
			else
				return _arr[idx];
		}

		Array<T>		&operator=(Array<T> const &rhs) {
			if (_arr)
				delete[] _arr;
			_len = rhs._len;
			_arr = new T[_len];
			for (unsigned int i = 0; i < _len; i++) {
				_arr[i] = rhs._arr[i];
			}
			return *this;
		}
	private:
		T				*_arr;
		unsigned int	_len;
};
#endif
