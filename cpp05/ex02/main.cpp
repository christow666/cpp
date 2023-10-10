/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:56:19 by cperron           #+#    #+#             */
/*   Updated: 2023/10/10 18:04:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	std::cout << "\033[1;31m Grade too low to sign(shrubbery)\033[0m" << std::endl;
    try {
        // Create a bureaucrat with a grade that can sign and execute the form
        Bureaucrat signer("John", 150); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

        // Create a bureaucrat with a grade that can execute the form
        Bureaucrat executor("Alice", 100); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("garden");
        std::cout << "Created ShrubberyCreationForm for: " << shrubberyForm.getAFormName() << std::endl;
		std::cout << "Grade to sign : " << static_cast<int>(shrubberyForm.getGradeToSign()) << std::endl;
		std::cout << "Grade to execute : " << static_cast<int>(shrubberyForm.getGradeToexec()) << std::endl;
		
		// Attempt to sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form (it's not signed)
        std::cout << "Attempting to execute the form (not signed)..." << std::endl;
        shrubberyForm.execute(executor);

        // Sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form again (now it's signed)
        std::cout << "Attempting to execute the form (signed)..." << std::endl;
        shrubberyForm.execute(executor);
    } catch (const Bureaucrat::FormNotSignedExeption& e) {
        // Catch and handle the FormNotSignedException
        std::cerr << "Failed to execute the form: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowExeption& e) {
        // Catch and handle the GradeTooLowException
        std::cerr << "Failed to execute : " << e.what() << std::endl;
    }
	
	std::cout << std::endl;
	std::cout << "\033[1;31m Grade ok to sign(shrubbery)\033[0m" << std::endl;

	try {
        // Create a bureaucrat with a grade that can sign and execute the form
        Bureaucrat signer("John", 145); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

        // Create a bureaucrat with a grade that can execute the form
        Bureaucrat executor("Alice", 100); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("garden");
        std::cout << "Created ShrubberyCreationForm for: " << shrubberyForm.getAFormName() << std::endl;
		std::cout << "Grade to sign : " << static_cast<int>(shrubberyForm.getGradeToSign()) << std::endl;
		std::cout << "Grade to execute : " << static_cast<int>(shrubberyForm.getGradeToexec()) << std::endl;


        // Sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form again (now it's signed)
        std::cout << "Attempting to execute the form (signed)..." << std::endl;
        shrubberyForm.execute(executor);
    } catch (const Bureaucrat::FormNotSignedExeption& e) {
        // Catch and handle the FormNotSignedException
        std::cerr << "Failed to execute the form: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowExeption& e) {
        // Catch and handle the GradeTooLowException
        std::cerr << "Failed to execute the form due to a low-grade bureaucrat: " << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "\033[1;31m Grade too low to exec(shrubbery)\033[0m" << std::endl;

	try {
        // Create a bureaucrat with a grade that can sign and execute the form
        Bureaucrat signer("John", 145); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

        // Create a bureaucrat with a grade that can execute the form
        Bureaucrat executor("Alice", 150); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("garden");
        std::cout << "Created ShrubberyCreationForm for: " << shrubberyForm.getAFormName() << std::endl;
		std::cout << "Grade to sign : " << static_cast<int>(shrubberyForm.getGradeToSign()) << std::endl;
		std::cout << "Grade to execute : " << static_cast<int>(shrubberyForm.getGradeToexec()) << std::endl;

        // Sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form again (now it's signed)
        std::cout << "Attempting to execute the form (signed)..." << std::endl;
        shrubberyForm.execute(executor);
    } catch (const Bureaucrat::FormNotSignedExeption& e) {
        // Catch and handle the FormNotSignedException
        std::cerr << "Failed to execute the form: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowExeption& e) {
        // Catch and handle the GradeTooLowException
        std::cerr << "Failed to execute the form : " << e.what() << std::endl;
    }

	std::cout << "\033[1;31m Grade too low to sign(shrubbery)\033[0m" << std::endl;
    try {
        // Create a bureaucrat with a grade that can sign and execute the form
        Bureaucrat signer("John", 150); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

        // Create a bureaucrat with a grade that can execute the form
        Bureaucrat executor("Alice", 100); // Adjust the grade as needed
        std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

        // Create a ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("garden");
        std::cout << "Created ShrubberyCreationForm for: " << shrubberyForm.getAFormName() << std::endl;
		std::cout << "Grade to sign : " << static_cast<int>(shrubberyForm.getGradeToSign()) << std::endl;
		std::cout << "Grade to execute : " << static_cast<int>(shrubberyForm.getGradeToexec()) << std::endl;
		
		// Attempt to sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form (it's not signed)
        std::cout << "Attempting to execute the form (not signed)..." << std::endl;
        shrubberyForm.execute(executor);

        // Sign the form
        std::cout << "Signing the form..." << std::endl;
        signer.signAForm(shrubberyForm);

        // Attempt to execute the form again (now it's signed)
        std::cout << "Attempting to execute the form (signed)..." << std::endl;
        shrubberyForm.execute(executor);
    } catch (const Bureaucrat::FormNotSignedExeption& e) {
        // Catch and handle the FormNotSignedException
        std::cerr << "Failed to execute the form: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowExeption& e) {
        // Catch and handle the GradeTooLowException
        std::cerr << "Failed to execute : " << e.what() << std::endl;
    }

	// std::cout << "\033[1;31m succes(robo)\033[0m\n" << std::endl;
	// try {
	// 	// Create a bureaucrat with a grade that can sign and execute the form
	// 	Bureaucrat signer("John", 15); // Adjust the grade as needed
	// 	std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

	// 	// Create a bureaucrat with a grade that can execute the form
	// 	Bureaucrat executor("Alice", 10); // Adjust the grade as needed
	// 	std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

	// 	// Create a RobotomyRequestForm
	// 	RobotomyRequestForm robotomyForm("target");
	// 	std::cout << "Created RobotomyRequestForm for: " << robotomyForm.getAFormName() << std::endl;
	// 	std::cout << "Grade to sign : " << static_cast<int>(robotomyForm.getGradeToSign()) << std::endl;
	// 	std::cout << "Grade to execute : " << static_cast<int>(robotomyForm.getGradeToexec()) << std::endl;

	// 	// Attempt to sign the form
	// 	std::cout << "Signing the form..." << std::endl;
	// 	signer.signAForm(robotomyForm);

		

	// 	// Execute the form
	// 	std::cout << "Executing the form (signed)..." << std::endl;
	// 	robotomyForm.execute(executor);
	// } catch (const Bureaucrat::FormNotSignedExeption& e) {
	// 	// Catch and handle the FormNotSignedException
	// 	std::cerr << "Failed to execute the form: " << e.what() << std::endl;
	// } catch (const Bureaucrat::GradeTooLowExeption& e) {
	// 	// Catch and handle the GradeTooLowException
	// 	std::cerr << "Failed to execute : " << e.what() << std::endl;
	// }

	std::cout << "\033[1;31m Grade too low to exec (robo)\033[0m\n" << std::endl;
	try {
		// Create a bureaucrat with a grade that can sign and execute the form
		Bureaucrat signer("John", 150); // Adjust the grade as needed
		std::cout << "Created bureaucrat: " << signer.getName() << ", Grade: " << static_cast<int>(signer.getGrade()) << std::endl;

		// Create a bureaucrat with a grade that can execute the form
		Bureaucrat executor("Alice", 100); // Adjust the grade as needed
		std::cout << "Created bureaucrat: " << executor.getName() << ", Grade: " << static_cast<int>(executor.getGrade()) << std::endl;

		// Create a RobotomyRequestForm
		RobotomyRequestForm robotomyForm("target");
		std::cout << "Created RobotomyRequestForm for: " << robotomyForm.getAFormName() << std::endl;
		std::cout << "Grade to sign : " << static_cast<int>(robotomyForm.getGradeToSign()) << std::endl;
		std::cout << "Grade to execute : " << static_cast<int>(robotomyForm.getGradeToexec()) << std::endl;

		// Attempt to sign the form
		std::cout << "Signing the form..." << std::endl;
		signer.signAForm(robotomyForm);

		

		// Execute the form
		std::cout << "Executing the form (signed)..." << std::endl;
		robotomyForm.execute(executor);
	} catch (const Bureaucrat::FormNotSignedExeption& e) {
		// Catch and handle the FormNotSignedException
		std::cerr << "Failed to execute the form: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowExeption& e) {
		// Catch and handle the GradeTooLowException
		std::cerr << "Failed to execute : " << e.what() << std::endl;
	}
    return 0;
}