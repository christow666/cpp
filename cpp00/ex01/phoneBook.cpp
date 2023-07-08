/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:20:02 by cperron           #+#    #+#             */
/*   Updated: 2023/07/07 21:55:45 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phoneBook.hpp"

int	main(int argc, char** argv) {
	PhoneBook phoneBook;
	std::string input;
	int	numberOfContact = 0;
	
	if (argc != 1) {
		std::cout << "Executable take no argument." << std::endl;
		return 1;
	}
	while (true) {
		std::cout << " Program accept only those entries : ADD, SEARCH & EXIT." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			phoneBook.addContact();
			std::cout << "Contact added." << std::endl;
			if (numberOfContact < 8)
				numberOfContact++;
		}
		else if (input == "SEARCH") {
			phoneBook.displayContactsList(numberOfContact);
		}
		else if (input == "EXIT") {
			std::cout << "Goodbye" << std::endl;
			return 0;
		}
	}
	return 0;
}
