/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:21:42 by cperron           #+#    #+#             */
/*   Updated: 2023/10/03 17:52:50 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

Form::Form(std::string formName, uint8_t gradeToSign, uint8_t gradeToExec) : _formName(formName), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToExec < 1 || gradeToSign < 1)
		throw Bureaucrat::GradeTooHighExeption();
	if (gradeToExec > 150 || gradeToSign > 150)
		throw Bureaucrat::GradeTooLowExeption();
}

Form::Form(const Form& other) : _formName(other._formName), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

Form& Form::operator=(const Form& other){
	if (this != &other) {
		_isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form(){}

const std::string &Form::getFormName() const{
	return _formName;
}

const bool &Form::getIsSigned() const{
	return _isSigned;
}

const uint8_t &Form::getGradeToSign() const{
	return _gradeToSign;
}

const uint8_t &Form::getGradeToexec() const{
	return _gradeToExec;
}

void Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= getGradeToSign())
		_isSigned = 1;
	else
		throw Bureaucrat::GradeTooLowExeption();
}

std::ostream &operator<<(std::ostream &out, const Form &other) {
  out << "Grade to execute:" << static_cast<int>(other.getGradeToexec())
      << " Grade to sign:" << static_cast<int>(other.getGradeToSign())
      << " Form name: " << other.getFormName()
      << " Is signed:" << other.getIsSigned() << std::endl;
  return out;
}