/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 23:42:45 by christo           #+#    #+#             */
/*   Updated: 2023/07/11 00:06:22 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

// Zombie::Zombie(std::string name){
// 	this->name = name;
// }

void	Zombie::setName(const std::string name){
	this->name = name;
}

void Zombie::annouce(void){
		std::cout << this->name << ": BraiiiiiiinnnzzzZ.." << std::endl;
	}

Zombie::~Zombie() {
        std::cout << "Destructor called for Zombie " << name << std::endl;
    }