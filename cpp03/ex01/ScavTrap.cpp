/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:58:45 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 13:37:33 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string Name, std::string TextColor) : ClapTrap(Name, TextColor){
	// std::cout << "ScavTrap named: " << Name << " constructed!" << std::endl;
	_HitPoint = 100;
	_EnergyPoint = 50;
	_AttackDamage = 20;
	_IsAKeeper = 0;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap named: " << this->_Name << " copy constructed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap named: " << this->_Name << " assigned!" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap named: " << _Name << " destroyed!" << std::endl;
}

int	ScavTrap::isAKeeper() const{
	return (this->_IsAKeeper);
}

void ScavTrap::guardGate() {
	_IsAKeeper = 3;
	_EnergyPoint -= 10;
    std::cout << _TextColor << _Name << " is now in Gatekeeper mode for " <<
		_IsAKeeper << " turn!" << std::endl;
	std::cout << _TextColor << _Name << " now has " <<
			_EnergyPoint << " Energy Point !" << std::endl;
}

void ScavTrap::decrementIsAKeeper() {
    _IsAKeeper--;
}