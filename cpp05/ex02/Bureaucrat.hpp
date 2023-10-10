/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:57:06 by cperron           #+#    #+#             */
/*   Updated: 2023/10/04 15:32:42 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	uint8_t _grade;
	
	Bureaucrat();
	

public:
	Bureaucrat(std::string name, uint8_t grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string &getName() const;
	const uint8_t &getGrade() const;
	
	class GradeTooHighExeption : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooLowExeption : public std::exception {
	public:
		const char* what() const throw();
	};
	class FormNotSignedExeption : public std::exception {
	public:
		const char* what() const throw();
	};

	void incrementGrade(uint8_t grade);
	void decrementGrade(uint8_t grade);

	void signAForm(AForm &Aform);
};

std::ostream& operator<< (std::ostream &out, const Bureaucrat &other);