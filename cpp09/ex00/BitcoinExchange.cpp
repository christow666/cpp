/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:17:51 by cperron           #+#    #+#             */
/*   Updated: 2023/11/13 16:04:54 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file){
	std::ifstream data;
	
	data.open(file);
	if (data.is_open()) {
		std::string line;
		
		while (std::getline(data, line)) {
			
			size_t commaPos = line.find(',');
   			if (commaPos != std::string::npos) {
        		std::string date = line.substr(0, commaPos);
				std::string value = line.substr(commaPos + 1);
				
				date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
				std::istringstream ss(date);
				int intDate;

				if (ss >> intDate){
					int i = 0;
					i = 0;
				}
				else 
					// std::cout << "Conversion failed" << std::endl;
					continue;
		
				try {
					float fvalue = std::stof(value);
					_data[intDate] = fvalue;
					// std::cout << "The integer value is: " << intDate << std::endl;
					// std::cout << std::fixed << std::setprecision(2) << fvalue << std::endl;
					// std::cout << date << std::endl;
				}
				catch (const std::exception& e) {
       				std::cerr << "Exception caught: " << e.what() << std::endl;
   				}
			}
			else
				std::cout << "Bad line format in file" << std::endl;
		}
	}
	else
		std::cout << "Failed to open file" <<std::endl;
	data.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other){
	 _data = other._data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange(){};

void BitcoinExchange::calculValue(std::string input){
	std::ifstream inputFile;

	inputFile.open(input);
	if (inputFile.is_open()) {
		std::string line;

		while (std::getline(inputFile, line)) {
			size_t pipePos = line.find('|');
			if (pipePos != std::string::npos) {
				std::string date = line.substr(0, pipePos);
				std::string numberOfBitcoin = line.substr(pipePos + 1);
				std::string dateStr = date;
				dateStr.erase(std::remove(dateStr.begin(), dateStr.end(), '-'), dateStr.end());
				std::istringstream ss(dateStr);
				int intDate;

				if (ss >> intDate){
					int i = 0;
					i = 0;
				}
				else 
					// std::cout << "Conversion failed" << std::endl;
					continue;
				try {
					if (isValidDate(date)) {
						float fNumberOfBitcoin = std::stof(numberOfBitcoin);
						if (fNumberOfBitcoin < 0 || fNumberOfBitcoin > 1000)
							throw std::runtime_error("Invalid argument: value must be non-negative or below 1000");
						// std::cout << std::fixed << std::setprecision(2) << fNumberOfBitcoin << std::endl;
						float value = findClosestDateValue(intDate);
						// std::string closetDate = findClosestDate(intDate);
						std::cout << date << "-> " << fNumberOfBitcoin << " = " << value * fNumberOfBitcoin << std::endl;
					}
				} 
				catch (const std::exception& e) {
       				std::cerr << "Exception caught: " << e.what() << std::endl;
   				}
			}
			else
				std::cout << "bad input : " << line << std::endl;
		}
	}
	else { 
		std::cout << "Failed to open file" <<std::endl;
	}
	inputFile.close();
}
//this is gettime for dinosaure
bool BitcoinExchange::isValidDate(const std::string& dateStr) {
    const char* dateFormat = "%Y-%m-%d";

    struct tm tm;
    if (strptime(dateStr.c_str(), dateFormat, &tm) == nullptr) {
    	throw std::runtime_error("Error: invalid date " + dateStr);
    }

    int year = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day = tm.tm_mday;

    if (year < 2009 || year > 2023 || month < 1 || month > 12 || day < 1 || day > 31) {
    	throw std::runtime_error("Error: invalid date " + dateStr);
    }
	return true;
}

float BitcoinExchange::findClosestDateValue(int intDate) {
    std::map<int, float>::iterator it = _data.lower_bound(intDate);
	if (it != _data.end()) {
		if (intDate == it->first)
			return it->second;
		it--;
		// std::cout << it->first << std::endl;
		// std::cout << "Found key: " << it->first << ", value: " << it->second << std::endl;
		return it->second;
    } else {
        std::cout << "Key not found" << std::endl;
    }
	return -1;
}