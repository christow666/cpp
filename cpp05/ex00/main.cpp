/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:56:19 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 14:56:30 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"

int main() {
  {
    try {
      Bureaucrat NotBozo("NotBozo", 69);
      NotBozo.decrementGrade(10);
      std::cout << NotBozo << std::endl;
      NotBozo.decrementGrade(0b01010000);
      std::cout << NotBozo << std::endl;
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
  std::cout << std::setw(38) << std::setfill('~')  << "" << std::endl;
  {
    try {
      Bureaucrat NotBozo("NotBozo", 69);
      NotBozo.incrementGrade(10);
      std::cout << NotBozo << std::endl;
      NotBozo.incrementGrade(69);
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      Bureaucrat NotBozo("NotBozo", 0xFF);
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
  std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
  {
    try {
      Bureaucrat NotBozo("NotBozo", 0b00000000);
    } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
    }
  }
  return 0;
}