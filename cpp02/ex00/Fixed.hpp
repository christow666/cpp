/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:51 by cperron           #+#    #+#             */
/*   Updated: 2023/07/25 22:17:23 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
	int		getRawBits()const;
	void	setRawBits(int const raw);
	
	Fixed();
	Fixed(const Fixed& fixed);
	~Fixed();
	Fixed& operator= (const Fixed& fixed);

private:
	int					_value;
	static const int	_fractionalBits;
} ;

#endif
