/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:27:53 by cperron           #+#    #+#             */
/*   Updated: 2023/10/10 19:40:36 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    try {
        if (formName == "ShrubberyCreationForm") {
            std::cout << "Intern creates " << formName << std::endl;
            return new ShrubberyCreationForm(target);
        } else if (formName == "RobotomyRequestForm") {
            std::cout << "Intern creates " << formName << std::endl;
            return new RobotomyRequestForm(target);
        } else if (formName == "PresidentialPardonForm") {
            std::cout << "Intern creates " << formName << std::endl;
            return new PresidentialPardonForm(target);
        } else {
            throw std::invalid_argument("Unknown form name");
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }
}