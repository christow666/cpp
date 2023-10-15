/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:20:56 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 14:57:02 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>


class Converter {
private:
	const std::string _argument;
	std::string _type;
	Converter();

	// char _charValue;
	// int _intValue;
	// float _floatValue;
	// double _doubleValue;
	
public:
	Converter(char *argument);
	Converter(const Converter& other);
	Converter& operator=(const Converter& other);
	~Converter();

	const std::string &getArgument() const;
	const std::string &getType() const;

	class BadArgument : public std::exception {
		const char* what() const throw();
	};

	void setType();
	void checkCharType();
	void checkIntType();
	void checkFloatType();
	void checkDoubleType();
	void checkSpecialType();

	void printConversion();
	void printForCharType();
	void printForIntType();
	void printForFloatType();
	void printForDoubleType();
	void printForSpecialType();
} ;