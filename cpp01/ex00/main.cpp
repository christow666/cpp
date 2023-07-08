/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:07:03 by christo           #+#    #+#             */
/*   Updated: 2023/07/08 01:19:48 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main() {
	Zombie* zombiePtr = newZombie("chad");
	zombiePtr->annouce();
	delete zombiePtr;

	randomChump("randy");

	return 0;
}