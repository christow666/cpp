/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:10:10 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 13:37:28 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

//////////////////////////////////////////////////////////////////////
//          CONSTRUCTOR, DESTRUCTOR AND OPERATOR OVERLAOD           //
//////////////////////////////////////////////////////////////////////

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string Name, std::string TextColor){
	// std::cout << "ClapTrap named: " << Name << " constructed!" << std::endl;
	_Name = Name;
	_TextColor = TextColor;
	_HitPoint = 10;
	_EnergyPoint = 10;
	_AttackDamage = 10;
	_HaveHP = true;
	_HaveEP = true;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	std::cout << _TextColor << other._Name << " copy constructed!" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(){
	// std::cout << this->_Name << " destroyed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	this->_Name = other._Name;
	this->_HitPoint = other._HitPoint;
	this->_EnergyPoint = other._EnergyPoint;
	this->_AttackDamage = other._AttackDamage;
	return *this;
}

void ClapTrap::someVirtualFunction() {
}

//////////////////////////////////////////////////////////////////////
//                             GETTER                               //
//////////////////////////////////////////////////////////////////////

std::string ClapTrap::getName()const{
	return(this->_Name);
}

int	ClapTrap::getHitPoint()const{
	return(this->_HitPoint);
}

int	ClapTrap::getEnergyPoint()const{
	return(this->_EnergyPoint);
}

int ClapTrap::getAttackDamage()const{
	return(this->_AttackDamage);
}

bool	ClapTrap::haveHP()const{
	return(this->_HaveHP);
}

bool	ClapTrap::haveEP()const{
	return(this->_HaveEP);
}

//////////////////////////////////////////////////////////////////////
//                          MEMBER   FONCTION                       //
//////////////////////////////////////////////////////////////////////


void	ClapTrap::attack(const std::string& target){
	std::cout << _TextColor << _Name << " attack " <<
		target << ", causing " << _AttackDamage << " points of damage !"
		<< std::endl;
}

void	ClapTrap::attackV2(ClapTrap& target){
	ScavTrap* scavTarget = dynamic_cast<ScavTrap*>(&target);
	std::cout << _TextColor << _Name << " attack " <<
		target.getName() << " for " << _AttackDamage << " points of damage !"
		<< std::endl;
    if (scavTarget && scavTarget->isAKeeper() > 0) {
		std::cout << "Damage taken is reduced to " << _AttackDamage / 2 <<
			" because you are a keeper" << std::endl;
		target.takeDamage(_AttackDamage / 2);
		scavTarget->decrementIsAKeeper();
	}
	else
		target.takeDamage(_AttackDamage);
	_EnergyPoint -= 2;
	if (_EnergyPoint <= 0){
		_HaveEP = false;
		std::cout << _TextColor << _Name << " is out of EP! GG" <<
			std::endl;
			exit(0);
	}
	else {
		std::cout << _TextColor << _Name << " now has " <<
			_EnergyPoint << " Energy Point !"
			<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	_HitPoint -= amount;
	if (_HitPoint > 0){
		std::cout << _TextColor << _Name << " now has " <<
			_HitPoint << " hitpoint !" << std::endl;
	}
	else {
		std::cout << _TextColor << _Name <<
			" has no more hp (he dead)! GG" << std::endl;
		_HaveHP = false;
		exit(0);
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (haveEP() && haveHP()){
		std::cout << _TextColor << _Name
			<< " repaired himself for " << amount << " hitpoint !" << std::endl;
		_HitPoint += amount;
		std::cout << _TextColor << _Name << " now has " <<
			_HitPoint << " hitpoint !" << std::endl;
		_EnergyPoint -= 2;
		std::cout << _TextColor << _Name << " now has " <<
			_EnergyPoint << " Energy Point !" << std::endl;
		if (_EnergyPoint <= 0){
			_HaveEP = false;
		}
	}
	else {
		std::cout << _TextColor << _Name << " is dead !" <<
			std::endl;
	}
	if (!haveEP()) {
		std::cout << _TextColor << _Name << " is out of EP! GG " <<
			std::endl;
			exit(0);
	}
}

