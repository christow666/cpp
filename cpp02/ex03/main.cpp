/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:25:11 by cperron           #+#    #+#             */
/*   Updated: 2023/07/30 23:11:06 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
    // Create three points representing the vertices of a triangle
    Point a(0.0f, 0.0f);
    Point b(2.0f, 0.0f);
    Point c(1.0f, 2.0f);

    // Create a point to check if it's inside the triangle
    Point testPoint(1.0f, 1.0f);

    // Check if the testPoint is inside the triangle using the bsp function
    if (Point::bsp(a, b, c, testPoint)) {
        std::cout << "The point is inside the triangle." << std::endl;
    }
	else {
        std::cout << "The point is outside the triangle." << std::endl;
    }
    return 0;
}