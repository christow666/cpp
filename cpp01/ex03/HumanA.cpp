/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:09:16 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 23:15:18 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(){}

HumanA::HumanA(std::string name, Weapon weapon){
	this->name = name;
	this->weapon = weapon;
}

void	HumanA::attack(){
		std::cout << name << " attacks with thier " << weapon.getType() << std::endl;
}