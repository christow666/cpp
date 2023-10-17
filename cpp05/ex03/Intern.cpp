/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:27:53 by cperron           #+#    #+#             */
/*   Updated: 2023/10/17 16:42:15 by cperron          ###   ########.fr       */
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

// AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
//     try {
//         if (formName == "ShrubberyCreationForm") {
//             std::cout << "Intern creates " << formName << std::endl;
//             return new ShrubberyCreationForm(target);
//         } else if (formName == "RobotomyRequestForm") {
//             std::cout << "Intern creates " << formName << std::endl;
//             return new RobotomyRequestForm(target);
//         } else if (formName == "PresidentialPardonForm") {
//             std::cout << "Intern creates " << formName << std::endl;
//             return new PresidentialPardonForm(target);
//         } else {
//             throw std::invalid_argument("Unknown form name");
//         }
//     } catch (const std::invalid_argument& e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return nullptr;
//     }
// }

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}	

typedef AForm* (Intern::*FormCreationMethod)(const std::string&);

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    // Define an array of function pointers
    FormCreationMethod creators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    // Define an array of corresponding form names
    const char* formNames[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    FormCreationMethod creator = nullptr;

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            creator = creators[i];
            break;
        }
    }

    if (creator) {
        return (this->*creator)(target);
    } else {
        std::cerr << "Error: " << formName << " is an unknown form." << std::endl;
        return nullptr;
    }
}
