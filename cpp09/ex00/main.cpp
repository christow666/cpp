/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:54:11 by cperron           #+#    #+#             */
/*   Updated: 2023/11/07 11:03:51 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv){
	if (argc == 2){
		std::string argument1(argv[1]);
		BitcoinExchange data("data.csv");
		data.calculValue("input.txt");
	}
	else
		std::cout << "bad number of arg" << std::endl;
	return 0;
}