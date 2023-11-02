/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 09:20:10 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 15:03:55 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Span.hpp"

#define sizeofbozo 10000

int main(){

	srand(static_cast<unsigned>(time(NULL)));

	try {
		int randomValue = rand();
		Span spr = Span(sizeofbozo);
		for (int i = 0; i < sizeofbozo; i++) {
			spr.addNumber(randomValue);
			randomValue = rand();
		}

		Span sp(sizeofbozo);
		sp.addRange(spr.getVector());
		// sp.printVector();
		int max = *std::max_element(sp.getVector().begin(), sp.getVector().end());
		int min = *std::min_element(sp.getVector().begin(), sp.getVector().end());
		std::cout << "min : " << min << std::endl;
		std::cout << "max : " << max << std::endl;
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;

	}
    catch(std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	return 0;
}