/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:42 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 21:48:58 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) /*: _value(fixed._value)*/ {
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;	
}

Fixed::Fixed(const int intValue) : _value(intValue << _fractionalBits){
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatValue)
	: _value(static_cast<int>(roundf(floatValue * (1 << _fractionalBits))))
	{
	// std::cout << "Float constructor called" << std::endl;	
}

Fixed::~Fixed(){
	// std::cout << "Destructor called" << std::endl;	
}

Fixed& Fixed::operator= (const Fixed& fixed){
	// std::cout << "Copy assigment operator called" << std::endl;
	if (this != &fixed) {
		_value = fixed.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator> (const Fixed& fixed)const{
	return(_value > fixed._value);
}

bool	Fixed::operator< (const Fixed& fixed)const{
	return(_value < fixed._value);
}

bool	Fixed::operator>= (const Fixed& fixed)const{
	return(_value >= fixed._value);
}

bool	Fixed::operator<= (const Fixed& fixed)const{
	return(_value <= fixed._value);
}

bool	Fixed::operator== (const Fixed& fixed)const{
	return(_value == fixed._value);
}

bool	Fixed::operator!= (const Fixed& fixed)const{
	return(_value != fixed._value);
}

Fixed	Fixed::operator+ (const Fixed& fixed)const{
	return (Fixed(static_cast<float>(_value) / (1 << _fractionalBits) +
			static_cast<float>(fixed._value) / (1 << _fractionalBits)));
}

Fixed	Fixed::operator- (const Fixed& fixed)const{
	return (Fixed(static_cast<float>(_value) / (1 << _fractionalBits) -
			static_cast<float>(fixed._value) / (1 << _fractionalBits)));
}

Fixed Fixed::operator*(const Fixed& rhs) const{
	Fixed result;
	
	result.setRawBits((_value * rhs.getRawBits()) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/ (const Fixed& fixed) const {
    Fixed result;
	
    result.setRawBits((_value << _fractionalBits) / fixed.getRawBits());
    return result;
}

Fixed&	Fixed::operator++ (){
	_value += 1;
	return (*this);
}

Fixed	Fixed::operator++ (int){
	Fixed tmp = *this;
	_value += 1;
	return (tmp);
}

Fixed&	Fixed::operator-- (){
	_value -= 1;
	return (*this);
}

Fixed	Fixed::operator-- (int){
	Fixed tmp = *this;
	_value -= 1;
	return (tmp);
}

int	Fixed::getRawBits()const{
	// std::cout << "getRawBits member function called" << std::endl;
    return _value;
}


void	Fixed::setRawBits(int const raw){
	// std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float	Fixed::toFloat()const{
	return (static_cast<float>(_value) / (1 << _fractionalBits));
}

int	Fixed::toInt()const{
	return (_value >> _fractionalBits);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b){
	if (a < b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b){
	if (a < b)
		return a;
	return b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b){
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<< (std::ostream& os, const Fixed& fixed){
	os << fixed.toFloat();
	return (os);
}
