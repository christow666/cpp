/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:39:24 by cperron           #+#    #+#             */
/*   Updated: 2023/07/10 17:11:40 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>


class Contact {
public:
	Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickName ,const std::string& phoneNumber,
			const std::string& darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getdarkestSecret() const;

	std::string fillField(std::string message);

private:
	Contact();
    std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;
} ;

#endif
