/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 00:54:15 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 01:07:55 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "MateriaSource.hpp"

// #include "AMateria.hpp"
// #include "Character.hpp"

// MateriaSource::MateriaSource() {
//   for (int i = 0; i < 5; i++) {
//     _inventory[i] = NULL;
//   }
// }

// MateriaSource::MateriaSource(const MateriaSource &other) { *this = other; }

// MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
//   for (int i = 0; i < 5; i++) {
//     _inventory[i] = other._inventory[i];
//   }
//   return *this;
// }

// MateriaSource::~MateriaSource() {
//   for (int i = 0; i < 5; i++) {
//     if (_inventory[i]) {
//       delete _inventory[i];
//     }
//   }
// }

// void MateriaSource::learnMateria(AMateria *materia) {
//   for (int i = 0; i < 5; i++) {
//     if (!_inventory[i]) {
//       _inventory[i] = materia;
//       break;
//     }
//   }
// 	std::cout << "Can't learn materia, reached the full amount" << std::endl;
// }

// AMateria *MateriaSource::createMateria(std::string const &type) {
//   for (int i = 0; i < 5; i++) {
//     if (!_inventory[i]) {
//       return NULL;
//     }
//     if (type == _inventory[i]->getType()) {
//       return _inventory[i]->clone();
//     }
//   }
//   return NULL;
// }

#include <iostream>
#include "MateriaSource.hpp"
// #include "ICharacter.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
        _inventory[i] = nullptr;
    }
}

// MateriaSource::MateriaSource(const MateriaSource &other){
// 	*this = other;
// }

// MateriaSource& MateriaSource::operator=(const MateriaSource &other){
// 	_type = other._type;
// 	return *this;
// }

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = nullptr;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete _inventory[i];
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = nullptr;
            }
        }
    }
    return *this;
}


MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete _inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m->clone();
		// delete m; // why? <----------------------------------------
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; ++i) {
        if (_inventory[i] && _inventory[i]->getType() == type) {
            return _inventory[i]->clone();
        }
    }
    return nullptr;
}