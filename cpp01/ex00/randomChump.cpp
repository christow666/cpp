/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 01:04:04 by christo           #+#    #+#             */
/*   Updated: 2023/07/08 01:15:03 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

void	randomChump(std::string name){
	Zombie* zombie = new Zombie(name);
	zombie->annouce();
	delete zombie;
}