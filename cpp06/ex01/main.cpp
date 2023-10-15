/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:20:53 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 15:30:46 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>

struct Data {
    int value;

    Data(int val) : value(val) {}
};

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    // Create a Data object
    Data* originalData = new Data(42);

    // Serialize the pointer to uintptr_t
    uintptr_t serializedData = serialize(originalData);

    // Deserialize the uintptr_t back to a pointer
    Data* deserializedData = deserialize(serializedData);

    // Check if the deserialized pointer is equal to the original pointer
    if (originalData == deserializedData) {
        std::cout << "Serialization and deserialization worked as expected. They are equal." << std::endl;
    } else {
        std::cout << "Serialization and deserialization did not work as expected. They are not equal." << std::endl;
    }

    // Clean up the dynamically allocated memory
    delete originalData;

    return 0;
}

// In the code provided, we're explicitly telling the compiler that we know what we're doing and that we
// want to reinterpret a pointer as an integer and vice versa, which is precisely what reinterpret_cast
// is meant for. This is typically used in cases where you're dealing with platform-specific memory addresses
// or serialization/deserialization processes.

