/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:04:33 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 10:47:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(){
	ClapTrap player("Player", "\x1b[32m");
	ClapTrap enemy("Enemy", "\x1b[31m");
	std::string input;
	
	std::cout << "welcome to CLapGame :D !! you can attack " <<
		"by writing attack or repair yourself by writing repair " << std::endl;
	std::cout << "if you write someting else you lose a turn" << std::endl;
	std::cout << "try to beat the enemy rdy?" << std::endl;
	std::getline(std::cin, input);
	while (true){
		enemy.attackV2(player);
		std::cout << "\x1b[0m";
		std::getline(std::cin, input);
		if (input == "attack"){
			player.attackV2(enemy);
		}
		else if (input == "repair"){
			player.beRepaired(5);
		}
		else {
			std::cout << "wrong input !! you lose a turn -_-" << std::endl;
		}
	}
}