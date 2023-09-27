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


// Default constructor
Dog::Dog() : _brain(new Brain()), _type("unknown") {}

// Parameterized constructor
Dog::Dog(std::string const& type) : _brain(new Brain()), _type(type) {}

// Copy constructor
Dog::Dog(const Dog& other) : _brain(new Brain(*(other._brain))), _type(other._type) {}

// Assignment operator overload
Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        // Deep copy Brain object
        delete _brain;
        _brain = new Brain(*(other._brain));
        
        _type = other._type;
    }
    return *this;
}

// Destructor
Dog::~Dog() {
    delete _brain;
}

// Make sound function
void Dog::makeSound() const {
    std::cout << "A " << _type << " dog says Woof!" << std::endl;
}

// Getter for Dog's idea (assuming Brain has a getIdeas() function)
const std::string* Dog::getDogIdea() const {
    return _brain->getIdeas();
}

// Getter for Dog's Brain
const Brain* Dog::getBrain() const {
    return _brain;
}
