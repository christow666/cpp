/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:04:33 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 14:41:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){
	FragTrap player("Player", "\x1b[32m");
	FragTrap enemy("Enemy", "\x1b[31m");
	std::string input;
	
	std::cout << "Entering level 3 :o your enemy is now a FragTrap!!" << std::endl;
	std::cout << "but dont worry you leveled up to and transformed into a Scavtrap" << std::endl;
	std::cout << "you can attack by writing attack or repair yourself by writing repair " << std::endl;
	std::cout << "you can now highfive by writing highfive" << std::endl;
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
			player.beRepaired(15);
		}
		else if (input == "highfive"){
			std::cout << "you are asking for a highfive now find someone" <<
				" to highfive you to gain bonus damage (write 5)" << std::endl;
			std::getline(std::cin, input);
			if (input == "5")
				player.highFivesGuys();
			else {
				std::cout << "you failed your highfive, sad." << std::endl;
			}
		}
		else {
			std::cout << "wrong input !! you lose a turn -_-" << std::endl;
		}
	}
}