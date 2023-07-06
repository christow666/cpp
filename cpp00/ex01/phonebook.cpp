/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:20:02 by cperron           #+#    #+#             */
/*   Updated: 2023/07/06 18:01:47 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


class Contact {
public:
	Contact(const std::string& name, const std::string& phoneNumber)
		: name(name), phoneNumber(phoneNumber) {}
		
	std::string getName() const {
		return name;
	}
	
	std::string getPhoneNumber() const {
        return phoneNumber;
    }
	
private:
    std::string name;
    std::string phoneNumber;
} ;

class PhoneBook {
public:
	PhoneBook()
		: contactsCount(0), {}

	void addContact(const std::string& name, const std::string& phoneNumber) {
        if (contactsCount < 8) {
            Contact newContact(name, phoneNumber);
            contacts[contactsCount] = newContact;
            contactsCount++;
        } else if (contactsCount == 8) {
            std::cout << "PhoneBook is full. Cannot add more contacts." << std::endl;
        }
    }

    void displayContacts() const {
        for (int i = 0; i < contactsCount; i++) {
            std::cout << "Contact " << (i + 1) << ":" << std::endl;
            std::cout << "Name: " << contacts[i].getName() << std::endl;
            std::cout << "Phone Number: " << contacts[i].getPhoneNumber() << std::endl;
            std::cout << std::endl;
        }
    }
	
private:
	Contact contacts[8];
	int	contactsCount;
} ;


int	main(int argc, char** argv) {
	if (argc != 1) {
		std::cout << "executable take no argument" << std::endl;
		return 1;
	}
	PhoneBook phoneBook;
	std::string input;
	std::cout << " Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT." << std::endl;
	while (true) {
		std::getline(std::cin, input);
		if (input == "ADD") {
			phoneBook.addContact("chris", "6969");
			std::cout << "ton input dude : " << input << std::endl;
		}
		else if (input == "SEARCH") {
			phoneBook.displayContacts();
		}
		else if (input == "EXIT") {
			std::cout << "Goodbye" << std::endl;
			return 0;
		}
	}
	return 0;
}