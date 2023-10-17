/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:18:23 by cperron           #+#    #+#             */
/*   Updated: 2023/10/17 16:41:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
	std::string _formArray[3];
	
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	
	AForm* createShrubberyCreationForm(const std::string& target);
	AForm* createRobotomyRequestForm(const std::string& target);
	AForm* createPresidentialPardonForm(const std::string& target);
	
	AForm *makeForm(const std::string &formName, const std::string &target);
} ;