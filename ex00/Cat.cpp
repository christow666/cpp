/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:07:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:22:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Default Cat constructed!" << std::endl;
}

// Cat::Cat(std::string const& type)  : Animal(type) {
// 	std::cout << _type << " constructed!" << std::endl;
// }

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << _type << " copy constructed!" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	_type = other._type;
	return *this;
}

Cat::~Cat(){
	std::cout << _type << " Cat destructed!" << std::endl;
}

void Cat::makeSound()const {
	std::cout << _type << " mehow mehow modafuka!" << std::endl;
}