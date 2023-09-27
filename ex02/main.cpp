/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:59:33 by cperron           #+#    #+#             */
/*   Updated: 2023/09/23 17:13:07 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {
    const int numAnimals = 4; // Half dogs, half cats
    Animal* animals[numAnimals];

    // Create Dog and Cat objects
    animals[0] = new Dog();
    animals[1] = new Dog();
    animals[2] = new Cat();
    animals[3] = new Cat();

    // Call makeSound on Cat and Dog objects
    for (int i = 0; i < numAnimals; ++i) {
        animals[i]->makeSound();
    }
	
	// Wont compile because animal is pure virtual.
	// Animal bug;
	// Animal bug2 = new Animal();

    // Clean up animals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    // Check for memory leaks (Brain created and Brain destroyed messages)
    return 0;
}