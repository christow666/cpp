/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomColor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:58:55 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 20:09:17 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomColor.hpp"

const std::string &RandomColors::randomizeTextColor(){
	std::srand(time(NULL));
	rng = rand();
	usleep(500000);
	std::srand(time(NULL));
	rng2 = rand();
	usleep(500000);
	std::srand(time(NULL));
	rng3 = rand();
	rng = (rng * rng2 / rng3) % 3;
	if (rng == 0){
		textColor = BoldRed;
		return (textColor);
	}
	else if (rng == 1){
		textColor = BoldGreen;
		return (textColor);
	}
	else{
		textColor = BoldYellow;
		return (textColor);
	}
}

const std::string &RandomColors::randomizeBackColor(){
	std::srand(time(NULL));
	rng = rand();
	usleep(500000);
	std::srand(time(NULL));
	rng2 = rand();
	usleep(500000);
	std::srand(time(NULL));
	rng3 = rand();
	rng = (rng * rng2 / rng3 + 19) % 3;
	if (rng == 0){
		backColor = YellowBackground;
		return (backColor);
	}
	else if (rng == 1){
		backColor = CyanBackground;
		return (backColor);
	}
	else{
		backColor = GreenBackground;
		return (backColor);
	}
}

const std::string &RandomColors::getTextColor(){
	textColor = randomizeTextColor();
	return (textColor);
}

const std::string &RandomColors::getBackColor(){
	backColor = randomizeBackColor();
	return (backColor);
}