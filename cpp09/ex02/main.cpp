/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:40:53 by cperron           #+#    #+#             */
/*   Updated: 2023/11/09 11:25:33 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"


int main(int argc, char **argv){
	if (argc > 2) {
		PmergeMe dafuq;
		dafuq.ftSort(argc, argv);
	
		return 0;
	}
	std::cout << "bad number of arg" << std::endl;
	return 1;
}