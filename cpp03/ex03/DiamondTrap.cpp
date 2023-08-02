/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:01:15 by cperron           #+#    #+#             */
/*   Updated: 2023/08/02 11:44:40 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()  {
    std::cout << "DiamondTrap constructed without a name!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name, std::string textColor)
    : ClapTrap(name, textColor), FragTrap(name + "_clap_name", textColor), ScavTrap(name, textColor) {
    _Name = name;
    _HitPoint = FragTrap::getHitPoint();
    _EnergyPoint = ScavTrap::getEnergyPoint();
    _AttackDamage = FragTrap::getAttackDamage();
    std::cout << "DiamondTrap named: " << _Name << " constructed!" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap named: " << _Name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : FragTrap(other), ScavTrap(other), _Name(other._Name) {
    std::cout << "DiamondTrap named: " << _Name << " copy constructed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _Name = other._Name;
    }
    std::cout << "DiamondTrap named: " << _Name << " assigned!" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << _TextColor << "DiamondTrap name: " << _Name << ", ClapTrap name: " << FragTrap::getName() << std::endl;
}