/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:27 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 17:00:56 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>

int main() {
    // Generate a random object
    Base randomObject;
	Base *ptr = randomObject.generate();
	
    // Identify the type using a Base pointer
    randomObject.identify(ptr);

	Base& ref = *ptr;
    // Identify the type using a Base reference
    randomObject.identify(ref);

	delete ptr;

    return 0;
}