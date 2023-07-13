/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:44:06 by cperron           #+#    #+#             */
/*   Updated: 2023/07/10 17:25:49 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickName ,const std::string& phoneNumber,
			const std::string& darkestSecret)
			: firstName(firstName), lastName(lastName), nickName(nickName),
			phoneNumber(phoneNumber), darkestSecret(darkestSecret){}

std::string Contact::getFirstName() const {
		return firstName;
	}

	std::string Contact::getLastName() const {
		return lastName;
	}
	
	std::string Contact::getNickName() const {
		return nickName;
	}
	
	std::string Contact::getPhoneNumber() const {
		return phoneNumber;
	}

	std::string Contact::getdarkestSecret() const {
		return darkestSecret;
	}
	
	std::string Contact::fillField(std::string message){
		std::string data;
		
		while (true){
			std::cout << message << std::endl;
			std::getline(std::cin, data);
			if(std::cin.fail()){
				return("noob");
			}
			if (data == "")
				std::cout << "Field cannot be empty" << std::endl;
			else 
				return (data);
		};
	}