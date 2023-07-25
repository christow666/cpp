/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:28:51 by cperron           #+#    #+#             */
/*   Updated: 2023/07/24 21:09:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Karen.hpp"

int main(int argc, char **argv) {
	if (argc == 2){
    	Karen karen;
		std::string level = argv[1];

		karen.chooseComplain(level);
	}
	else {
		std::cout << "Error: Program always take 1 argument." << std::endl;
	}
    return 0;
}