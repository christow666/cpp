/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:57:06 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 17:18:44 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

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
		const char* what() const throw();
	};
	class GradeTooLowExeption : public std::exception {
		const char* what() const throw();
	};

	void incrementGrade(uint8_t grade);
	void decrementGrade(uint8_t grade);

	void signForm(Form &form);
};

std::ostream& operator<< (std::ostream &out, const Bureaucrat &other);