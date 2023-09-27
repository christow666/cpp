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

// Default constructor
Cat::Cat() : _brain(new Brain()), _type("unknown") {}

// Parameterized constructor
Cat::Cat(std::string const& type) : _brain(new Brain()), _type(type) {}

// Copy constructor
Cat::Cat(const Cat& other) : _brain(new Brain(*(other._brain))), _type(other._type) {}

// Assignment operator overload
Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        // Deep copy Brain object
        delete _brain;
        _brain = new Brain(*(other._brain));
        
        _type = other._type;
    }
    return *this;
}

// Destructor
Cat::~Cat() {
    delete _brain;
}

// Make sound function
void Cat::makeSound() const {
    std::cout << "A " << _type << " cat says Meow!" << std::endl;
}

// Getter for Cat's idea
const std::string* Cat::getCatIdea() const {
    return _brain->getIdeas(); // Assuming Brain has a getIdeas() function
}

// Getter for Cat's Brain
const Brain* Cat::getBrain() const {
    return _brain;
}
