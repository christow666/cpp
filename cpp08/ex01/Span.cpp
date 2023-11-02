/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:30:35 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 14:49:16 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int N): _maxSize(N), _vector() {}

Span::Span(const Span &other){
	*this = other;
}

Span& Span::operator=(const Span &other){
	if (this == &other)
		return *this;
	_maxSize = other._maxSize;
	_vector.clear();
	_vector.resize(other._vector.size());
	_vector.assign(other._vector.begin(), other._vector.end());
	return *this;
}

Span::~Span(){}

void Span::addNumber(int number){
	if (_vector.size() >= _maxSize)
		throw MaxSize();
	_vector.push_back(number);
}

void Span::addRange(std::vector<int> containerToAdd){
	if (_vector.size() + containerToAdd.size() > _maxSize)
		throw MaxSize();
	_vector.insert(_vector.end(), containerToAdd.begin(), containerToAdd.end());
}


int Span::shortestSpan() {
	Span copy = *this;
	if (copy.getVector().size() <= 1)
		throw NoSpan();
	int shortSpan = -1;
	int diff;
	std::sort(copy.getVector().begin(), copy.getVector().end());
	for (std::vector<int>::iterator it = copy.getVector().begin(); it != copy.getVector().end() - 1; it++) {
		if (shortSpan < 0)
			shortSpan = *(it + 1) - *it;
		diff = *(it + 1) - *it;
		if (diff < shortSpan)
			shortSpan = diff;
	}
	return shortSpan;
}

int Span::longestSpan(){
	Span copy = *this;
	if (copy.getVector().size() <= 1)
		throw NoSpan();
	std::sort(copy.getVector().begin(), copy.getVector().end());
	if (copy.getVector().back() == *copy.getVector().begin())
		throw NoSpan();
	return copy.getVector().back() - *copy.getVector().begin();
}

void Span::printVector(){
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++) {
		std::cout << *it << " " ;
	}
	std::cout << std::endl;
}

std::vector<int> &Span::getVector() {
	return _vector;
}

std::vector<int>::iterator Span::getBegin() {
	return _vector.begin();
}

std::vector<int>::iterator Span::getEnd() {
	return _vector.end();
}

const char *Span::MaxSize::what() const throw(){
	return "Vector is full";
}

const char *Span::NoSpan::what() const throw(){
	return "No Span found";
}