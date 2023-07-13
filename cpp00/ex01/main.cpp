/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:55:33 by cperron           #+#    #+#             */
/*   Updated: 2023/07/10 17:16:43 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(int argc, char** argv) {
	PhoneBook phoneBook;
	std::string input;
	int	numberOfContact = 0;
	
	(void)argv;
	if (argc != 1) {
		std::cout << "Executable take no argument." << std::endl;
		return 1;
	}
	while (true) {
		std::cout << " Program accept only those entries : ADD, SEARCH & EXIT." << std::endl;
		std::getline(std::cin, input);
		if(std::cin.fail()){
			break;
		}
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