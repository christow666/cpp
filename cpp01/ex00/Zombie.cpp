/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:22:37 by cperron           #+#    #+#             */
/*   Updated: 2023/07/11 17:27:47 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(const std::string name) : name(name) {}

void Zombie::annouce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Destructor called for Zombie " << name << std::endl;
}