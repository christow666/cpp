/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:54:34 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 22:45:46 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

void	Weapon::setType(std::string type){
	this->type = type;
}

const std::string&	Weapon::getType(){
	return (type);
}
