/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:27 by cperron           #+#    #+#             */
/*   Updated: 2023/10/24 16:23:49 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <time.h>

int main() {
    Base randomObject;
	Base *ptr = randomObject.generate();
	
    randomObject.identify(ptr);

	Base& ref = *ptr;
    
    randomObject.identify(ref);

	delete ptr;

    return 0;
}