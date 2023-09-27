/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:22:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Default dog constructed!" << std::endl;
}

// Dog::Dog(std::string const& type)  : Animal(type) {
// 	std::cout << _type << " constructed!" << std::endl;
// }

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << _type << " copy constructed!" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	_type = other._type;
	return *this;
}

Dog::~Dog(){
	std::cout << _type << " dog destructed!" << std::endl;
}

void Dog::makeSound()const {
	std::cout << _type << " set on fire (wouaf)!" << std::endl;
}