/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:18:57 by cperron           #+#    #+#             */
/*   Updated: 2023/11/01 13:10:31 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"


int main() {
	//good test
	
    try {
        // Create an empty array
        Array<int> emptyArray;
        std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

        // Create an array with 5 elements initialized to zero
        int size = 5;
        Array<int> intArray(size);
        for (int i = 0; i < size; ++i) {
            intArray[i] = i * 10;
        }

		std::cout << "before swap" << std::endl;
		for (int i = 0; i < intArray.size(); ++i) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }
		
        // Copy the array
        Array<int> copiedArray = intArray;
		
		std::cout << "copy the array" <<std::endl;
        // Modify the original array
        intArray[3] = 42;
		
		std::cout << "after swap" << std::endl;
        // Print the elements of the original and copied arrays
        for (int i = 0; i < intArray.size(); ++i) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        for (int i = 0; i < copiedArray.size(); ++i) {
            std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;
        }
    }
    catch(std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


	//bad test

   try {
        int size = -5;
        Array<double> doubleArray(size);
        for (int i = 0; i < size; ++i) {
            doubleArray[i] = i * 10;
        }

    }
    catch(std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }	 
	try {
        int size = 5;
        Array<double> doubleArray(size);
        for (int i = 0; i < size + 6; ++i) {
            doubleArray[i] = i * 10;
        }

    }
    catch(std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}