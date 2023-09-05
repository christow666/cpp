/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:49:01 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 01:10:05 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Ice.hpp"

// #include <iostream>

// Ice::Ice() : AMateria("ice") {}

// Ice::Ice(const Ice &other) : AMateria(other) { *this = other; }

// Ice& Ice::operator=(const Ice &other) {
//     if (this != &other) {
//         AMateria::operator=(other);
//     }
//     return *this;
// }

// Ice::~Ice() {}

// void Ice::use(ICharacter &target) {
//  std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
// }

// AMateria *Ice::clone() const { return (new Ice(*this)); }

#include <iostream>
#include "Ice.hpp"

Ice::Ice() :AMateria("ice"){}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::Ice(const Ice &other) : AMateria(other) {
	*this = other;
}

Ice& Ice::operator=(const Ice &other){
	_type = other._type;
	return *this;
}

Ice::~Ice(){}

std::string const &Ice::getType() const{
	return _type;
}

AMateria* Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}