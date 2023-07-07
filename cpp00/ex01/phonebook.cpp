/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:20:02 by cperron           #+#    #+#             */
/*   Updated: 2023/07/07 19:49:33 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


class Contact {
public:
	Contact(const std::string& firstName, const std::string& lastName, 
			const std::string& nickName, const std::string& phoneNumber,
			const std::string& darkestSecret)
		: firstName(firstName), lastName(lastName), nickName(nickName),
			phoneNumber(phoneNumber), darkestSecret(darkestSecret){}
		
	std::string getFirstName() const {
		return firstName;
	}

	std::string getLastName() const {
		return lastName;
	}
	
	std::string getNickName() const {
		return nickName;
	}
	
	std::string getPhoneNumber() const {
        return phoneNumber;
    }

	std::string getDarkestSecret() const {
        return darkestSecret;
    }
	
	// void	getContactInfo(){
	// 	firstName = checkEmptyField("Enter your first name.");
	// 	lastName = checkEmptyField("Enter your last name.");
	// 	nickName = checkEmptyField("Enter your nickname.");
	// 	phoneNumber = checkEmptyField("Enter your phone number.");
	// 	darkestSecret = checkEmptyField("Enter your darkest secret.");
	// 	phoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	// }
	
private:
    std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
} ;

class PhoneBook {
public:
    PhoneBook() : contacts(new Contact*[8]), contactsCount(0) {}

    ~PhoneBook() {
        delete[] contacts;
    }

	// void	accesPhoneBook(){
	// 	contacts[contactsCount]->getContactInfo();
		
	// }
    void	addContact(const std::string& firstName, const std::string& lastName, 
			const std::string& nickName, const std::string& phoneNumber,
			const std::string& darkestSecret) {
        if (contactsCount < 8) {
            contacts[contactsCount] = new Contact(firstName, lastName,
						nickName, phoneNumber, darkestSecret);
            contactsCount++;
        } else {
			contactsCount = 0;
            addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
        }
    }


    void	displayContacts(int i) const {
		if (i < 0)
			return ;
		std::cout << "| " << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << contacts[i]->getFirstName() << " | ";
		std::cout << std::setw(10) << contacts[i]->getLastName() << " | ";
		std::cout << std::setw(10) << contacts[i]->getNickName() << " | " << std::endl;
    }

private:
    Contact** contacts;
    int contactsCount;
};

std::string	checkEmptyField(std::string message){
	std::string data;
	
	while (true){
		std::cout << message << std::endl;
		std::getline(std::cin, data);
		if (data == "")
			std::cout << "Field cannot be empty" << std::endl;
		else 
			return (data);
	}
}

void	getContactInfo(PhoneBook& phoneBook){
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = checkEmptyField("Enter your first name.");
	lastName = checkEmptyField("Enter your last name.");
	nickName = checkEmptyField("Enter your nickname.");
	phoneNumber = checkEmptyField("Enter your phone number.");
	darkestSecret = checkEmptyField("Enter your darkest secret.");
	phoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

int	selectIndex(int antisegfault){
	std::string index;
	int i;
	
	while (true){
		std::cout << "Enter contact number 1 - 8." << std::endl;
		std::getline(std::cin, index);
		std::istringstream iss(index);
		if (iss >> i && i >= 1 && i <= 8){
			if (i - 1 >= antisegfault){
				std::cout << "Contact is empty." << std::endl;
				return -1;
			}
			return(i - 1);
		}
	}
}

int	main(int argc, char** argv) {
	if (argc != 1) {
		std::cout << "Executable take no argument." << std::endl;
		return 1;
	}
	PhoneBook phoneBook;
	std::string input;
	int	antisegfault = 0;
	while (true) {
		std::cout << " Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT." << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD") {
			// phoneBook.accesPhoneBook();
			getContactInfo(phoneBook);
			std::cout << "Contact added." << std::endl;
			if (antisegfault < 8)
				antisegfault++;
		}
		else if (input == "SEARCH") {
			phoneBook.displayContacts(selectIndex(antisegfault));
		}
		else if (input == "EXIT") {
			std::cout << "Goodbye." << std::endl;
			return 0;
		}
	}
	return 0;
}
        // for (int i = 0; i < contactsCount; i++) {
        //     std::cout << "Contact " << (i + 1) << ":" << std::endl;
        //     std::cout << "Fisrt name: " << contacts[i]->getFirstName() << std::endl;
		// 	std::cout << "Last name: " << contacts[i]->getLastName() << std::endl;
		// 	std::cout << "Nickname: " << contacts[i]->getNickName() << std::endl;
        //     std::cout << "Phone Number: " << contacts[i]->getPhoneNumber() << std::endl;
		// 	std::cout << "Darkest secret: " << contacts[i]->getDarkestSecret() << std::endl;
        //     std::cout << std::endl;
        // }