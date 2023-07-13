/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:45:27 by christo           #+#    #+#             */
/*   Updated: 2023/07/12 14:14:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:

	std::string name;
	
public:
	Zombie();
	Zombie(const std::string name);
	
	void	annouce(void);
	void	setName(const std::string name);

	~Zombie();
} ;

Zombie* zombieHorde(int N, std::string name);

#endif 