/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:38:54 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 17:02:09 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <time.h>

Base::~Base(){};

Base* Base::generate(){
	srand(time(nullptr));
	int randomNum = rand() % 3;
  if (randomNum == 1)
    return dynamic_cast<Base *>(new A);
  else if (randomNum == 2)
    return dynamic_cast<Base *>(new B);
  else
    return dynamic_cast<Base *>(new C);
}

void Base::identify(Base* p) {
	std::cout << "Identifying pointer type" << std::endl;
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "Base reference is A" << std::endl;
    }
	else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "Base reference is B" << std::endl;
    }
	else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "Base reference is C" << std::endl;
	}
}

void Base::identify(Base& p) {
  std::cout << "Identifying reference type" << std::endl;
  try {
    A &aResult = dynamic_cast<A &>(p);
    (void)aResult;
    std::cout << "Base reference is A" << std::endl;
	return ;
  } catch (std::exception &exception) {}
  try {
    B &bResult = dynamic_cast<B &>(p);
    (void)bResult;
    std::cout << "Base reference is B" << std::endl;
	return ;
  } catch (std::exception &exception) {}
  try {
    C &cResult = dynamic_cast<C &>(p);
    (void)cResult;
    std::cout << "Base reference is C" << std::endl;
  } catch (std::exception &exception) {}
}

