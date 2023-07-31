/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:51 by cperron           #+#    #+#             */
/*   Updated: 2023/07/25 22:44:19 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	int		getRawBits()const;
	void	setRawBits(int const raw);
	float	toFloat()const;
	int		toInt()const;
	
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator= (const Fixed& fixed);

private:
	int					_value;
	static const int	_fractionalBits = 8;
} ;

std::ostream& operator<< (std::ostream& os, const Fixed& fixed);

#endif
