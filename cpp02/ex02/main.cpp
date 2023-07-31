/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:11 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 22:03:09 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

int main(){
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed d(-1);
	std::cout << "a : " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "a++ : " << a++ << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	std::cout << "max (a, b) : " << Fixed::max( a, b ) << std::endl;
	std::cout << "min (a, b) : " << Fixed::min( a, b ) << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "c-- : " << c-- << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "a + c : " << a + c << std::endl;
	std::cout << "a - c : " << a - c << std::endl;
	std::cout << "a == a : " << (a == a) << std::endl;
	std::cout << "a != a : " << (a != a) << std::endl;
	std::cout << "a >= a : " << (a >= a) << std::endl;
	std::cout << "a <= a : " << (a <= a) << std::endl;
	std::cout << "a >= c : " << (a >= c) << std::endl;
	std::cout << "a <= c : " << (a <= c) << std::endl;
	std::cout << "a > a : " << (a > a) << std::endl;
	std::cout << "a > c : " << (a > c) << std::endl;
	std::cout << "a > d : " << (a > d) << std::endl;
	std::cout << "a < a : " << (a < a) << std::endl;
	std::cout << "a < c : " << (a < c) << std::endl;
	std::cout << "a < d : " << (a < d) << std::endl;
	return 0;
}