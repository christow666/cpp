/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:21:42 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 17:52:50 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

AForm::AForm(std::string AformName, uint8_t gradeToSign, uint8_t gradeToExec) : _AformName(AformName), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToExec < 1 || gradeToSign < 1)
		throw Bureaucrat::GradeTooHighExeption();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw Bureaucrat::GradeTooLowExeption();
}

AForm::AForm(const AForm& other) : _AformName(other._AformName), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm& AForm::operator=(const AForm& other){
	if (this != &other) {
		_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm(){}

const std::string &AForm::getAFormName() const{
	return _AformName;
}

const bool &AForm::getIsSigned() const{
	return _isSigned;
}

const uint8_t &AForm::getGradeToSign() const{
	return _gradeToSign;
}

const uint8_t &AForm::getGradeToexec() const{
	return _gradeToExec;
}

void AForm::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= getGradeToSign())
		_isSigned = 1;
	else
		throw Bureaucrat::GradeTooLowExeption();
}

void AForm::execute(const Bureaucrat& executor) const {
        if (!_isSigned) {
            throw Bureaucrat::FormNotSignedExeption();
        }
        if (executor.getGrade() > _gradeToExec) {
            throw Bureaucrat::GradeTooLowExeption();
        }
		executeAction();
    }

std::ostream &operator<<(std::ostream &out, const AForm &other) {
  out << "Grade to execute:" << static_cast<int>(other.getGradeToexec())
      << " Grade to sign:" << static_cast<int>(other.getGradeToSign())
      << " Form name: " << other.getAFormName()
      << " Is signed:" << other.getIsSigned() << std::endl;
  return out;
}

