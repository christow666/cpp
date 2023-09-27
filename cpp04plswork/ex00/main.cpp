/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:59:33 by cperron           #+#    #+#             */
/*   Updated: 2023/08/10 10:12:57 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int	main(){
// 	// Animal velcrot;
// 	//Dog rookie;
// 	Animal *rookie = new Dog();
	
// 	rookie->makeSound();
// 	delete rookie;
// }

int	main(){

	// pointer test 
	
	std::cout << "Pointer test" << std::endl;
	std::cout << "Good animal" << std::endl;
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " <- dog type " << std::endl;
	std::cout << i->getType() << " <- cat type " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << " Wrong animal" << std::endl;
	const WrongAnimal* wrongJ = new WrongCat();
	
	std::cout << wrongJ->getType() << "  <- wrongCat type " << std::endl;
	wrongJ->makeSound();
	
	delete wrongJ;
	
	std::cout << std::endl;
	std::cout << std::endl;

	// normal test
	std::cout << "Normal test" << std::endl;
	std::cout << "Good animal" << std::endl;
	std::cout << std::endl;

	Animal nmeta;
	Dog ni;
	Cat nj;

	std::cout << nj.getType() << " <- dog type " << std::endl;
	std::cout << ni.getType() << " <- cat type " << std::endl;
	ni.makeSound(); //will output the cat sound!
	nj.makeSound();
	nmeta.makeSound();

	std::cout << std::endl;
	std::cout << " Wrong animal" << std::endl;
	
	WrongCat nwrongJ;
	
	nwrongJ.makeSound();
	
	return 0;
}