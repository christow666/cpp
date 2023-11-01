/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:56:47 by cperron           #+#    #+#             */
/*   Updated: 2023/11/01 11:06:49 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T, size_t N>
size_t arraySize(const T (&)[N]) {
    return N;
}

template <typename T>
void iter(T *array, int array_size, void func(T const &content)){
	for (int index = 0; index < array_size; index++){
		func(array[index]);
	}
}

template <typename T>
void printElement(T element){
	std::cout << element << " ";
}