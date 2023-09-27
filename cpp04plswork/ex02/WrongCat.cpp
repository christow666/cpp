/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:22:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "Default WrongCat constructed!" << std::endl;
}

// WrongCat::WrongCat(std::string const& type)  : WrongAnimal(type) {
// 	std::cout << _type << " constructed!" << std::endl;
// }

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << _type << " copy constructed!" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	_type = other._type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << _type << " WrongCat destructed!" << std::endl;
}

void WrongCat::makeSound()const {
	std::cout << _type << "! wohem wohem akufadom" << std::endl;
}