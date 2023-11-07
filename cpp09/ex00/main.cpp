/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:54:11 by cperron           #+#    #+#             */
/*   Updated: 2023/11/06 15:12:08 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv){	
		BitcoinExchange data("data.csv");
		data.calculValue("input.txt");
	(void)argv;
	(void)argc;

}