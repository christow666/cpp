/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:19:19 by cperron           #+#    #+#             */
/*   Updated: 2023/11/01 13:02:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
class Array {
public:
	Array() : _array(NULL), _size(0) {}
	
	Array(int &n) {
		if (n < 0)
			throw NegativeArraySize();
		_size = n;
		_array = new T[_size];
	}
	
	Array(const Array &other){
		*this = other;
	}
	
	Array& operator=(Array const &other){
		if (this == &other)
			return *this;
		_size = other.size();
		_array = new T[_size];
		for (int i = 0; i < _size; i++)
		_array[i] = other[i];
		return *this;
	}
	
	T &operator[](int index) const {
		if (index < 0 || index > (_size - 1))
			throw OutOfArrayRange();
		return _array[index];
 	}
	
	~Array() {
		delete[] _array;
	}

	int size() const {
		return _size;
	}
	
	class NegativeArraySize : public std::exception {
	public:
		const char* what() const throw() {
			return "Negative array size";
		}
	};
	
	class OutOfArrayRange : public std::exception {
	public:
		const char* what() const throw() {
			return "Out of array range";
		}
	};
	
private:
	T* _array;
	int _size;
} ;