/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:46:27 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal"){
	std::cout << "Default constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << _type << " constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << _type << " copy constructed!" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << _type << " destructed!" << std::endl;
}

void WrongAnimal::makeSound()const{
	std::cout << _type << " Some wrong animal sound" << std::endl;
}

const std::string &WrongAnimal::getType() const{
	return _type;
}