/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomColor.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:02:49 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 20:09:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <chrono>
#include <string>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

#define Reset "\033[0m"
#define BoldRed "\033[1;31m"
#define BoldGreen "\033[1;32m"
#define BoldYellow "\033[1;33m"
#define GreenBackground "\033[42m"
#define YellowBackground "\033[43m"
#define CyanBackground "\033[46m"


class RandomColors {
private:
	std::string textColor;
	std::string backColor;
	int rng;
	int	rng2;
	int	rng3;
	
public:
	RandomColors(){}
	
	~RandomColors(){}
	
	const std::string&	randomizeTextColor();
	const std::string&	randomizeBackColor();
	const std::string& getTextColor();
	const std::string& getBackColor();
	
} ;
