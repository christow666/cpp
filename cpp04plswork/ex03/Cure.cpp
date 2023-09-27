/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:48:14 by cperron           #+#    #+#             */
/*   Updated: 2023/09/26 16:27:54 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Cure.hpp"

Cure::Cure() :AMateria("cure"){}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(const Cure &other) : AMateria(other) {
	*this = other;
}

Cure& Cure::operator=(const Cure &other){
	_type = other._type;
	return *this;
}

Cure::~Cure(){
	// delete this;
}

std::string const &Cure::getType() const{
	return _type;
}

AMateria* Cure::clone() const{
	return (new Cure(*this));
}


void Cure::use(ICharacter& target){
	std::cout << "* heals "
		<< target.getName()<< "'s wounds *" << std::endl;
}