/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:46:03 by cperron           #+#    #+#             */
/*   Updated: 2023/10/24 21:30:57 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int main(int argc, char **argv){
	if (argc == 2){
		try {
			Converter number(argv[1]);
			// std::cout << "Arg : " << number.getArgument() << std::endl;
			number.setType();
			// std::cout << "Type : " << number.getType() << std::endl;
			number.printConversion();
		}
		catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}		
	}
	else {
		std::cout << "Bad number of arg" << std::endl;
	}
	return 0;
}