/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:59:33 by cperron           #+#    #+#             */
/*   Updated: 2023/09/23 16:54:56 by cperron          ###   ########.fr       */
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

    // Test deep copy of animals
    Animal* copiedAnimals[numAnimals];
    for (int i = 0; i < numAnimals; ++i) {
        copiedAnimals[i] = new Animal(*(animals[i]));
    }

    // Access and display ideas of cats and dogs
    for (int i = 0; i < numAnimals; ++i) {
        Cat* cat = dynamic_cast<Cat*>(animals[i]); // Check if it's a Cat
        Dog* dog = dynamic_cast<Dog*>(animals[i]); // Check if it's a Dog

        if (cat != nullptr) {
            const std::string* ideas = cat->getCatIdea();
            std::cout << "Cat's ideas:" << std::endl;
            for (int j = 0; j < 100; ++j) {
                std::cout << ideas[j] << std::endl;
            }
        } else if (dog != nullptr) {
            const std::string* ideas = dog->getDogIdea();
            std::cout << "Dog's ideas:" << std::endl;
            for (int j = 0; j < 100; ++j) {
                std::cout << ideas[j] << std::endl;
            }
        }
    }

    // Clean up animals and copiedAnimals
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
        delete copiedAnimals[i];
    }

    // Check for memory leaks (Brain created and Brain destroyed messages)
    return 0;
}