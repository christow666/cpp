/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:44:58 by christo           #+#    #+#             */
/*   Updated: 2023/07/07 21:53:10 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact {
public:
	Contact(const std::string& darkestSecret, const std::string& phoneNumber,
			const std::string& nickName, const std::string& lastName,
			const std::string& firstName)
		:	darkestSecret(darkestSecret), phoneNumber(phoneNumber),
			nickName(nickName), lastName(lastName), firstName(firstName){}
	
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

	std::string getdarkestSecret() const {
		return darkestSecret;
	}
	
	std::string fillField(std::string message){
		std::string data;
		
		while (true){
			std::cout << message << std::endl;
			std::getline(std::cin, data);
			if (data == "")
				std::cout << "Field cannot be empty" << std::endl;
			else 
				return (data);
		};
	}
	
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
	
	void	addContact() {
        if (contactsCount < 8) {
            contacts[contactsCount] = new Contact(
					contacts[contactsCount]->fillField("Enter your darkest secret."),
					contacts[contactsCount]->fillField("Enter your phone number."),
					contacts[contactsCount]->fillField("Enter your nickname."),
					contacts[contactsCount]->fillField("Enter your last name."),
					contacts[contactsCount]->fillField("Enter your first name."));
            contactsCount++;
        } else {
			contactsCount = 0;
            addContact();
        }
    }

	std::string	resizedInfo(std::string info) const{
		if (info.length() > 10)
			return (info.substr(0, 9) + ".");
		else
			return (info);
	}
	
	void	displaycontact(int index) const{
			std::cout << contacts[index]->getFirstName() << std::endl;
			std::cout << contacts[index]->getLastName() << std::endl;
			std::cout << contacts[index]->getNickName() << std::endl;
			std::cout << contacts[index]->getPhoneNumber() << std::endl;
			std::cout << contacts[index]->getdarkestSecret() << std::endl;
	}
	
	int	selectIndex(int numberOfContact) const{
		std::string index;
		int i;
		
		while (true){
			std::cout << "Enter contact number 1 - 8." << std::endl;
			std::getline(std::cin, index);
			std::istringstream iss(index);
			if (iss >> i && i >= 1 && i <= 8){
				if (i - 1 >= numberOfContact)
					std::cout << "Contact is empty." << std::endl;
				else
					return(i - 1);
			}
		}
	}

	void	displayContactsList(int numberOfContact) const{
		if (numberOfContact == 0){	
			std::cout << "Contact list is empty." << std::endl;
			return;
		}
		else for (int i = 0; i < numberOfContact; i++){	
			std::cout << "| " << std::setw(10) << i + 1 << " | ";
			std::cout << std::setw(10) << resizedInfo(contacts[i]->getFirstName()) << " | ";
			std::cout << std::setw(10) << resizedInfo(contacts[i]->getLastName()) << " | ";
			std::cout << std::setw(10) << resizedInfo(contacts[i]->getNickName()) << " | " << std::endl;
		}
		displaycontact(selectIndex(numberOfContact));
	}

private:
    Contact** contacts;
    int contactsCount;
};

#endif