/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:25:40 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 10:27:08 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>

class Span{
private:
	Span();
	unsigned int _size;
	std::vector<int> _vector;
	
public:
	Span(unsigned int N);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int number);
	// int shortestSpan();
	int longestSpan();

	class MaxSize : public std::exception{
		const char *what() const throw();
	};

	class NoSpan : public std::exception{
		const char *what() const throw();
	};
};