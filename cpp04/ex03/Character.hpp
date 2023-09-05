/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:19:34 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 01:42:38 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter ;

class Character : public ICharacter {
private:
	std::string _name;
	AMateria* 	_inventory[4];
	Character();

	AMateria *_floorPointers[100];
	int	_pointerCount;
	
public:
	Character(std::string const &name);
	Character(Character const &other);
	Character& operator=(const Character &other);
	virtual ~Character();
	
	std::string const &getName()const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	void addFloor(AMateria* m);
	void clearFloor();
} ;