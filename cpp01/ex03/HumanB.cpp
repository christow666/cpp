/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:09:16 by cperron           #+#    #+#             */
/*   Updated: 2023/07/17 19:16:48 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name), weapon(NULL) {
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void	HumanB::attack() const{
	
	if (!weapon)
		std::cout << name << " attackz with f*ckall "<< std::endl;
	else
		std::cout << name << " attackz with their " << weapon->getType() << std::endl;
}
