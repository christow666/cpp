/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:45:27 by christo           #+#    #+#             */
/*   Updated: 2023/07/08 01:22:13 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie {
private:

	std::string name;
	
public:
	Zombie(const std::string name) : name(name) {}
	
	
	void annouce(void){
		std::cout << name << " BraiiiiiiinnnzzzZ.." << std::endl;
	}

	~Zombie() {
        std::cout << "Destructor called for Zombie " << name << std::endl;
    }
} ;

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif