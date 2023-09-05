/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:26:26 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 15:41:51 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

// int main()
// {
// IMateriaSource* src = new MateriaSource();
// delete src;
// return 0;
// src->learnMateria(new Ice());
// src->learnMateria(new Cure());
// ICharacter* me = new Character("me");
// AMateria* tmp;
// tmp = src->createMateria("ice");
// me->equip(tmp);
// tmp = src->createMateria("cure");
// me->equip(tmp);
// ICharacter* bob = new Character("bob");
// me->use(0, *bob);
// me->use(1, *bob);
// delete bob;
// delete me;
// delete src;
// return 0;
// }

int main()
{
    //Ice ice;
	IMateriaSource* src = new MateriaSource();
   // src->learnMateria(&ice);
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	AMateria* tmp;
	
	
	me->use(0, *me);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp; // free because I couldn't equip
	
	delete me;
	delete src;
	
	return 0;
	
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);
	
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	bob->equip(tmp);
	tmp = src->createMateria("ice");
	bob->equip(tmp);

	me->use(0, *me);
	me->use(1, *me);
	me->use(2, *me);
	me->use(3, *me);
	me->use(4, *me);
	
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(4);
	
	delete bob;
	delete me;
	delete src;
	
	return 0;
}
