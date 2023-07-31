/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:43:17 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 23:07:43 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point& Point::operator= (const Point& other) {
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const{
	return x;
}

Fixed Point::getY()const {
	return y;
}

bool  Point::bsp(Point const& a, Point const& b, Point const& c, Point const& point) {
    // Barycentric coordinate method to check if a point is inside a triangle
    Fixed denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());

    Fixed alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
    Fixed gamma = Fixed(1) - alpha - beta;

    return (alpha >= 0 && beta >= 0 && gamma >= 0);
}