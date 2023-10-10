/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:56:19 by cperron           #+#    #+#             */
/*   Updated: 2023/10/10 19:46:45 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;

    // Example usage of the Intern class
    AForm* form1 = intern.makeForm("ShrubberyCreationForm", "garden");
    AForm* form2 = intern.makeForm("RobotomyRequestForm", "patient");

    if (form1 != nullptr && form2 != nullptr) {
        // Attempt to sign and execute the forms
        try {
            Bureaucrat bureaucrat("John", 1); // Adjust the grade as needed
            std::cout << "Created bureaucrat: " << bureaucrat.getName() << ", Grade: " << static_cast<int>(bureaucrat.getGrade()) << std::endl;

            std::cout << "Signing the first form..." << std::endl;
            bureaucrat.signAForm(*form1);

            std::cout << "Executing the first form..." << std::endl;
            form1->execute(bureaucrat);

            std::cout << "Signing the second form..." << std::endl;
            bureaucrat.signAForm(*form2);

            std::cout << "Executing the second form..." << std::endl;
            form2->execute(bureaucrat);
        } catch (const Bureaucrat::FormNotSignedExeption& e) {
            // Catch and handle the FormNotSignedException
            std::cerr << "Failed to execute the form: " << e.what() << std::endl;
        } catch (const Bureaucrat::GradeTooLowExeption& e) {
            // Catch and handle the GradeTooLowException
            std::cerr << "Failed to execute : " << e.what() << std::endl;
        }

        // Clean up memory
        delete form1;
        delete form2;
    } else {
        std::cerr << "Failed to create one or more forms." << std::endl;
    }

    return 0;
}