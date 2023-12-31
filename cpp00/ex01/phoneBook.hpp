/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:44:58 by christo           #+#    #+#             */
/*   Updated: 2023/07/12 14:39:59 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
	
    ~PhoneBook();
	
	void		addContact();
	std::string	resizedInfo(std::string info) const;
	void		displaycontact(int index) const;
	int			selectIndex(int numberOfContact) const;
	void		displayContactsList(int numberOfContact) const;

private:
    Contact** contacts;
    int contactsCount;
};

#endif