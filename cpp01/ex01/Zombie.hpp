/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:45:27 by christo           #+#    #+#             */
/*   Updated: 2023/07/11 00:06:18 by christo          ###   ########.fr       */
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
	Zombie() : name("") {}
	
	void	annouce(void);
	void	setName(const std::string name);

	~Zombie();
} ;

Zombie* zombieHorde(int N, std::string name);

#endif