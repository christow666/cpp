/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:04:50 by cperron           #+#    #+#             */
/*   Updated: 2023/11/07 11:28:01 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>

class BitcoinExchange {
private:
	std::map<int, float> _data;
	BitcoinExchange();

public:
	BitcoinExchange(std::string file);
	// BitcoinExchange(const BitcoinExchange& other);
	// BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void calculValue(std::string input);
	bool isValidDate(const std::string& dateStr);
	float findClosestDateValue(int intDate);
	
} ;