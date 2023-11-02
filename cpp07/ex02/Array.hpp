/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:19:19 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 09:44:36 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array {
public:
	Array() : _array(NULL), _size(0) {}
	
	Array(unsigned int n) {
		_size = n;
		_array = new T[_size];
	}
	
	Array(const Array &other){
		_array = NULL;
		*this = other;
	}
	
	Array& operator=(const Array &other){
		if (this == &other)
			return *this;
		if (_array)
			delete[] _array;
		_size = other.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		_array[i] = other[i];
		return *this;
	}
	
	T &operator[](unsigned int index) const {
		if (index < 0 || index > (_size - 1))
			throw OutOfArrayRange();
		return _array[index];
 	}
	
	~Array() {
		delete[] _array;
	}

	unsigned int size() const {
		return _size;
	}
	
	class OutOfArrayRange : public std::exception {
	public:
		const char* what() const throw() {
			return "Out of array range";
		}
	};
	
private:
	T* _array;
	unsigned int _size;
} ;