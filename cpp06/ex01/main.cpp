/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:20:53 by cperron           #+#    #+#             */
/*   Updated: 2023/10/26 15:37:45 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

struct Data {
    int value;
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data originalData;
	originalData.value = 42;
	Data *ptr = &originalData;
	
	std::cout << "original value " << originalData.value << std::endl;

    uintptr_t serializedData = serialize(ptr);
	std::cout << "serialized value " << serializedData << std::endl;

    Data* deserializedData = deserialize(serializedData);
	std::cout << "desirialized value " << deserializedData->value << std::endl;

    if (ptr == deserializedData) {
        std::cout << "Serialization and deserialization worked as expected. They are equal." << std::endl;
    } else {
        std::cout << "Serialization and deserialization did not work as expected. They are not equal." << std::endl;
    }
    return 0;
}


