/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:42 by cperron           #+#    #+#             */
/*   Updated: 2023/07/25 22:46:30 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) : _value(fixed._value) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;	
}

Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBits){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
	: _value(static_cast<int>(roundf(floatValue * (1 << _fractionalBits)))){
	std::cout << "Float constructor called" << std::endl;	
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;	
}

Fixed& Fixed::operator= (const Fixed& fixed){
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &fixed) {
		_value = fixed.getRawBits();
	}
	// this->_value = fixed.getRawBits();
	return *this;
}

int	Fixed::getRawBits()const{
	std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float	Fixed::toFloat()const{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int	Fixed::toInt()const{
	return (_value >> _fractionalBits);
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}
