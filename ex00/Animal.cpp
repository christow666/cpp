/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:46:27 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal"){
	std::cout << "Default constructed!" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << _type << " constructed!" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << _type << " copy constructed!" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	_type = other._type;
	return *this;
}

Animal::~Animal(){
	std::cout << _type << " destructed!" << std::endl;
}

void Animal::makeSound()const{
	std::cout << _type << " anoying sound!" << std::endl;
}

const std::string &Animal::getType() const{
	return _type;
}