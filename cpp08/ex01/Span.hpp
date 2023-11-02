/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:25:40 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 14:26:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

class Span{
private:

	Span();
	unsigned int _maxSize;
	std::vector<int> _vector;
	
public:
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int number);
	void addRange(std::vector<int> containerToAdd);
	int shortestSpan();
	int longestSpan();
	void printVector();

	std::vector<int> &getVector();
	std::vector<int>::iterator getBegin();
	std::vector<int>::iterator getEnd();

	class MaxSize : public std::exception{
		const char *what() const throw();
	};

	class NoSpan : public std::exception{
		const char *what() const throw();
	};
};