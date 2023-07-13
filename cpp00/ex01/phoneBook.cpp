/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:20:02 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 14:40:28 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts(new Contact*[8]), contactsCount(0) {}

PhoneBook::~PhoneBook() {
    for (int i = 0; i < contactsCount; i++) {
        delete contacts[i];
    }
    delete[] contacts;
}
	
void	PhoneBook::addContact() {
	if (contactsCount < 8) {
    	contacts[contactsCount] = new Contact(
			contacts[contactsCount]->fillField("Enter your first name."),
			contacts[contactsCount]->fillField("Enter your last name."),
			contacts[contactsCount]->fillField("Enter your nickname."),
			contacts[contactsCount]->fillField("Enter your phone number."),
			contacts[contactsCount]->fillField("Enter your darkest secret."));
        contactsCount++;
	}
	else {
		contactsCount = 0;
        addContact();
    }
}

std::string	PhoneBook::resizedInfo(std::string info) const{
	if (info.length() > 10)
		return (info.substr(0, 9) + ".");
	else
		return (info);
}
	
void	PhoneBook::displaycontact(int index) const{
		std::cout << contacts[index]->getFirstName() << std::endl;
		std::cout << contacts[index]->getLastName() << std::endl;
		std::cout << contacts[index]->getNickName() << std::endl;
		std::cout << contacts[index]->getPhoneNumber() << std::endl;
		std::cout << contacts[index]->getdarkestSecret() << std::endl;
}
	
int	PhoneBook::selectIndex(int numberOfContact) const{
	std::string index;
	int i;

	while (true){
		std::cout << "Enter contact number 1 - 8." << std::endl;
		std::getline(std::cin, index);
		if(std::cin.fail()){
			return (-2);
		}
		std::istringstream iss(index);
		if (iss >> i && i >= 1 && i <= 8){
			if (i - 1 >= numberOfContact)
				std::cout << "Contact is empty." << std::endl;
			else
				return(i - 1);
		}
	}
}

void	PhoneBook::displayContactsList(int numberOfContact) const{
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
	int ret = selectIndex(numberOfContact);
	if (ret == -2)
		return;
	else
		displaycontact(ret);
}