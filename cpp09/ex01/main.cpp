/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:22:01 by cperron           #+#    #+#             */
/*   Updated: 2023/11/14 11:16:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc == 2){
		std::string argument1(argv[1]);
		if (argument1.empty()){
			std::cout << "bad arg" << std::endl;
			return 1;
		}
		for (std::string::const_iterator it = argument1.begin(); it != argument1.end(); ++it) {
        	if (!std::isspace(*it)) {
        		RPN toSolve(argument1);
				toSolve.solveEquation();
				return 0;
			}
		}
		std::cout << "bad arg" << std::endl;
		return 1;
	}
	std::cout << "bad number of arg" << std::endl;
	return 1;	
}

// too much number