/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:34:39 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 23:08:26 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// #include <iostream>
// #include <cmath>
#include "Fixed.hpp"

class Point {
private:
	const Fixed  x;
	const Fixed  y;

public:
	Point();
	Point(float x, float y);
	Point(const Point& other);
	Point& operator= (const Point& other);
	~Point();
	
	Fixed getX() const;
	Fixed getY() const;
	
	static bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);
} ;
