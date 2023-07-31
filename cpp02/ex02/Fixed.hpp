/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:51 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 21:19:13 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	int				getRawBits()const;
	void			setRawBits(int const raw);
	float			toFloat()const;
	int				toInt()const;
	Fixed&			min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	Fixed&			max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
	
	
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed& fixed);
	~Fixed();
	
	Fixed& 	operator= (const Fixed& fixed);
	bool	operator> (const Fixed& fixed)const;
	bool	operator< (const Fixed& fixed)const;
	bool	operator>= (const Fixed& fixed)const;
	bool	operator<= (const Fixed& fixed)const;
	bool	operator== (const Fixed& fixed)const;
	bool	operator!= (const Fixed& fixed)const;
	Fixed	operator+ (const Fixed& fixed)const;
	Fixed	operator- (const Fixed& fixed)const;
	Fixed	operator* (const Fixed& fixed)const;
	Fixed	operator/ (const Fixed& fixed)const;
	Fixed&	operator++ ();
	Fixed	operator++ (int);
	Fixed&	operator-- ();
	Fixed	operator-- (int);
	
	

private:
	int					_value;
	static const int	_fractionalBits = 8;
} ;

std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
