/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:45:27 by christo           #+#    #+#             */
/*   Updated: 2023/07/11 17:28:48 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie {
private:
	Zombie();
	std::string name;
	
public:
	Zombie(const std::string name);
	
	void annouce(void);

	~Zombie();
} ;

void	randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif