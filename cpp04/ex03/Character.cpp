/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:32:22 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 15:42:52 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _pointerCount(0) {
	for (int i = 0; i < 4; i++){
		_inventory[i] = NULL;
	}
}

Character::Character(const Character &other) : ICharacter(other) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        }
		else {
            _inventory[i] = nullptr;
        }
    }
}

Character& Character::operator=(const Character &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
            }
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
			else {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}

Character::~Character(){
	for (int i = 0; i < 4; i++){
		if (_inventory[i])
			delete _inventory[i];	
	}
}

std::string const &Character::getName() const{
	return _name;
}

void Character::equip(AMateria* m){
	for (int i = 0; i < 4; i++){
		if(_inventory[i] == NULL){
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "my ballsbag is full" << std::endl;
}

void Character::unequip(int idx){
	addFloor(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
	if (idx < 4){
		if (_inventory[idx])
			_inventory[idx]->use(target);
	}
}

void Character::addFloor(AMateria *materia) {
 	if (_pointerCount == 100)
    	clearFloor();
	_floorPointers[_pointerCount] = materia;
	_pointerCount++;
}

void Character::clearFloor() {
	while (_pointerCount != 0) {
		_pointerCount--;
		delete _floorPointers[_pointerCount];
	}
	_pointerCount = 0;
}