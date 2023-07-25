/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:07:19 by cperron           #+#    #+#             */
/*   Updated: 2023/07/24 21:16:56 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

Karen::Karen(){
	level_array[0] = "DEBUG";
	level_array[1] = "INFO";
	level_array[2] = "WARNING";
	level_array[3] = "ERROR";
}

Karen::~Karen(){}

void	Karen::debug(){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void	Karen::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Karen:: warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Karen::error(){
	std::cout << "This is unacceptable! I want to speak to the manager now!" << std::endl;
}

void	Karen::chooseComplain(std::string level){
	int	case_index = -1;
	
	for (int i = 0; i < 4; i++){
		if (level_array[i] == level){
			case_index = i;
			break;
		}
	}
	
	switch (case_index) {
		case 0 :
				Karen::complain(level_array[case_index]);
				case_index++;
		case 1 :
				Karen::complain(level_array[case_index]);
				case_index++;
		case 2 :
				Karen::complain(level_array[case_index]);
				case_index++;
		case 3 :
				Karen::complain(level_array[case_index]);
				break;
		default :
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;	
	}
	
}

void	Karen::complain(std::string level){
	void (Karen::*fc_pointer[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	
	std::cout << "[ " << level << " ]" << std::endl;
	for (int i = 0; i < 4; i++){
		if (level_array[i] == level){
			(this->*fc_pointer[i])();
			std::cout << std::endl;
			return ;
		}
	}
}
