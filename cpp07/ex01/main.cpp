/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:56:51 by cperron           #+#    #+#             */
/*   Updated: 2023/11/01 11:05:58 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Iter.hpp"

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = arraySize(intArray);

    std::cout << "int Array : ";
    iter(intArray, intArraySize, printElement);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArraySize = arraySize(doubleArray);

    std::cout << "docule Array : ";
    iter(doubleArray, doubleArraySize, printElement);
    std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArraySize = arraySize(charArray);

    std::cout << "char Array : ";
    iter(charArray, charArraySize, printElement);
    std::cout << std::endl;

    return 0;
}