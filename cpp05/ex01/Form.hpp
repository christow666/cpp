/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:26:25 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 17:29:16 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string _formName;
	bool _isSigned;
	const uint8_t _gradeToSign;
	const uint8_t _gradeToExec;

	Form();

public:
	Form(std::string formName, uint8_t gradeToSign, uint8_t gradeToExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();
	
	const std::string &getFormName() const;
	const bool &getIsSigned() const;
	const uint8_t &getGradeToSign() const;
	const uint8_t &getGradeToexec() const;

	void beSigned(Bureaucrat bureaucrat);
	

};

std::ostream& operator<< (std::ostream &out, const Form &other);