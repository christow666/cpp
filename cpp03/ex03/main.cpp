/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:04:33 by cperron           #+#    #+#             */
/*   Updated: 2023/08/02 11:53:29 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(){
	DiamondTrap player("Player", "\x1b[32m");
	DiamondTrap enemy("Enemy", "\x1b[31m");
	std::string input;
	int question = 0;
	
	std::cout << "Entering level 4 :o your enemy is now a DiamondTrap!!" << std::endl;
	std::cout << "but dont worry you leveled up and transformed into a DiamondTrap" << std::endl;
	std::cout << "you can attack by writing attack or repair yourself by writing repair " << std::endl;
	std::cout << "you can now ask yourself who am i ? by writing question" << std::endl;
	std::cout << "if you write someting else you lose a turn" << std::endl;
	std::cout << "try to beat the enemy rdy?" << std::endl;
	std::getline(std::cin, input);
	while (true){
		if (question == 0)
			enemy.attackV2(player);
		else
			question--;
		std::cout << "\x1b[0m";
		std::getline(std::cin, input);
		if (input == "attack"){
			player.attackV2(enemy);
		}
		else if (input == "repair"){
			player.beRepaired(15);
		}
		else if (input == "question"){
			std::cout << "You are asking youself an existential question and answer it :" << std::endl;
			player.whoAmI();
			std::cout << "\x1b[0m" << "Then its your enemy who seen to question himself and skip 2 turn :" << std::endl;
			enemy.whoAmI();
			question = 2;
		}
		else {
			std::cout << "wrong input !! you lose a turn -_-" << std::endl;
		}
	}
}