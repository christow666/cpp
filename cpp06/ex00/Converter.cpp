/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:33:28 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 15:13:42 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <iomanip>
#include "Converter.hpp"

Converter::Converter(char* argument) : _argument(argument), _type("none"){}

Converter::Converter(const Converter& other) : _argument(other._argument) , _type(other._type){}

Converter& Converter::operator=(const Converter& other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

Converter::~Converter(){};

const std::string &Converter::getArgument() const {
	return _argument;
}

const std::string &Converter::getType() const {
	return _type;
}

const char* Converter::BadArgument::what() const throw(){
	return "Bad argument";
}

void Converter::setType(){
	checkCharType();
	checkIntType();
	checkFloatType();
	checkDoubleType();
	checkSpecialType();
	if (_type == "none")
		throw BadArgument();
}

void Converter::checkCharType(){
	int charValue = static_cast<int>(_argument[0]);
	
	if (_argument.length() == 1 && charValue >= 32 && charValue <= 126){
		_type = "char";
	}
}

void Converter::checkIntType(){
	char* end;
    double number = std::strtod(_argument.c_str(), &end);

    if (*end == '\0' && number >= INT_MIN && number <= INT_MAX) {
		// std::cout << "The int value is: " << number << std::endl;
		_type = "int";
    }
}

void Converter::checkFloatType(){
	std::string input;
	if (!_argument.empty() && _argument.back() == 'f' && _argument.find('.') != std::string::npos) {
        input = _argument.substr(0, _argument.length() - 1);
		char* end;
    	float number = std::strtof(input.c_str(), &end);

		if (*end == '\0' && number >= -FLT_MAX && number <= FLT_MAX) {
			if (number <= -FLT_MIN || number >= FLT_MIN || number == 0){
	    		// std::cout << "The float value is: " << number << std::endl;
				_type = "float";
			}
		}
	}
}

void Converter::checkDoubleType(){
	if (_argument.find('.') != std::string::npos){
		char* end;
		double number = std::strtod(_argument.c_str(), &end);
		(void)number;
		if (*end == '\0') {
			// std::cout << "The double value is: " << number << std::endl;
			_type = "double";
		}
	}
}

void Converter::checkSpecialType(){
	if (_argument == "-inff" || _argument == "+inff" || _argument == "nanf")
		_type = "sfloat";
	if (_argument == "-inf" || _argument == "+inf" || _argument == "nan")
		_type = "sdouble";
}

void Converter::printConversion(){
	if (_type == "char")
		printForCharType();
	if (_type == "int")
		printForIntType();
	if (_type == "float")
		printForFloatType();
	if (_type == "double")
		printForDoubleType();
	if (_type[0] == 's')
		printForSpecialType();
}

void Converter::printForCharType(){
	char numberChar = _argument[0];
	std::cout << "char: '" << numberChar << "'" << std::endl;
	int numberInt = static_cast<int>(numberChar);
	std::cout << "int: " << numberInt << std::endl;
	float numberFloat = static_cast<float>(numberChar);
	std::cout << "float: " << numberFloat << ".0f" << std::endl;
	double numberDouble = static_cast<double>(numberChar);
	std::cout << "double: " << numberDouble << ".0" << std::endl;	
}

void Converter::printForIntType(){
	int	numberInt = atoi(_argument.c_str());
	char numberChar = static_cast<char>(numberInt);
	if (numberInt >= 26 && numberInt <= 132)
		std::cout << "char: '" << numberChar << "'" << std::endl;
	else
	 	std::cout << "char: thanks you cpp for reminding me about the range of printable character" << numberChar << std::endl;
	std::cout << "int: " << numberInt << std::endl;
	float numberFloat = static_cast<float>(numberInt);
	std::cout << "float: " << numberFloat << ".0f" << std::endl;
	double numberDouble = static_cast<double>(numberInt);
	std::cout << "double: " << numberDouble << ".0" << std::endl;	
}

void Converter::printForFloatType(){
	char* end;
    float numberFloat = std::strtof(_argument.c_str(), &end);
	char numberChar = static_cast<char>(numberFloat);
	if (numberFloat >= 26 && numberFloat <= 132)
		std::cout << "char: '" << numberChar << "'" << std::endl;
	else
	 	std::cout << "char: thanks you cpp for reminding me about the range of printable character" << numberChar << std::endl;
	int numberInt = static_cast<int>(numberFloat);
	std::cout << "int: " << numberInt << std::endl;
	if (_argument.find(".0f") != std::string::npos)
		std::cout << "float: " << numberFloat << ".0f" << std::endl;
	else
		std::cout << "float: " << numberFloat << "f" << std::endl;
	double numberDouble = static_cast<double>(numberFloat);
	if (_argument.find(".0f") != std::string::npos)
		std::cout << "double: " << numberDouble << ".0" << std::endl;
	else
		std::cout << "double: " << numberDouble << std::endl;
}

void Converter::printForDoubleType(){
	char* end;
	double numberDouble = std::strtod(_argument.c_str(), &end);
	char numberChar = static_cast<char>(numberDouble);
	if (numberDouble >= 26 && numberDouble <= 132)
		std::cout << "char: '" << numberChar << "'" << std::endl;
	else
	 	std::cout << "char: thanks you cpp for reminding me about the range of printable character" << numberChar << std::endl;
	int numberInt = static_cast<int>(numberDouble);
	std::cout << "int: " << numberInt << std::endl;
	float numberFloat = static_cast<float>(numberDouble);
	std::cout << "float: " << numberFloat << "f" << std::endl;
    if (_argument.length() >= 2 && _argument.substr(_argument.length() - 2) == ".0") 
		std::cout << "double: " << numberDouble << ".0" << std::endl;
    else 
		std::cout << "double: " << numberDouble << std::endl;
}

void Converter::printForSpecialType(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (_type == "sfloat"){
		std::cout << "float: " << _argument << std::endl;
		std::string special = _argument.substr(0, _argument.size() - 1);
        std::cout << "double: " << special << std::endl;
	}
	else {
		std::cout << "float: " << _argument  << "f" << std::endl;
        std::cout << "double: " << _argument << std::endl;
	}	
}

