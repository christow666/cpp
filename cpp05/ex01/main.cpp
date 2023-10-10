/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:56:19 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 17:54:00 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// Bureaucrat karlos("Karlos", 10);
	// Form shitForm("ShitForm", 150, 150);
	// Form goodForm("GoodForm", 1, 1);

	// karlos.signForm(shitForm);
	// karlos.signForm(goodForm);
	
	

	// return 0;
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 50, 5);
			bozo.signForm(form);
			bozo.incrementGrade(50);
			bozo.signForm(form);
		}
		catch(std::exception &exception) {
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 19);
			Form form("Clown fiesta", 50, 5);
			bozo.signForm(form);
		}
		catch (std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 0, 15);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::setfill('~') << std::setw(38) << "" << std::endl;
	{
		try{
			Bureaucrat bozo("Bozo", 69);
			Form form("Clown fiesta", 255, 5);
		}
		catch(std::exception &exception){
			std::cout << exception.what() << std::endl;
		}
	}
	return 0;
}