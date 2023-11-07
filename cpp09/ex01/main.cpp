/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:22:01 by cperron           #+#    #+#             */
/*   Updated: 2023/11/07 13:30:30 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv){
	if (argc == 2){
		std::string argument1(argv[1]);
		RPN toSolve(argument1);
		toSolve.solveEquation();
		return 0;
	}
	std::cout << "bad number of arg" << std::endl;
	return 1;
}