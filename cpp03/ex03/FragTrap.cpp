/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:30:42 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 14:42:23 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(std::string Name, std::string TextColor) : ClapTrap(Name, TextColor){
	// std::cout << "FragTrap named: " << Name << " constructed!" << std::endl;
	_HitPoint = 100;
	_EnergyPoint = 100;
	_AttackDamage = 30;
	_IsAKeeper = 0;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap named: " << this->_Name << " copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap named: " << this->_Name << " assigned!" << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap named: " << _Name << " destroyed!" << std::endl;
}

void	FragTrap::highFivesGuys(){
	_AttackDamage += 20;
	std::cout << "HIGHFIVE !!!!!!!!!!!" << std::endl;
}