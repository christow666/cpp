/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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

class AForm {
private:
	const std::string _AformName;
	bool _isSigned;
	const uint8_t _gradeToSign;
	const uint8_t _gradeToExec;

	AForm();

public:
	AForm(std::string formName, uint8_t gradeToSign, uint8_t gradeToExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();
	
	const std::string &getAFormName() const;
	const bool &getIsSigned() const;
	const uint8_t &getGradeToSign() const;
	const uint8_t &getGradeToexec() const;

	void beSigned(Bureaucrat bureaucrat);
	
	virtual void execute(const Bureaucrat& executor) const;
	virtual void executeAction() const = 0;
};

std::ostream& operator<< (std::ostream &out, const AForm &other);