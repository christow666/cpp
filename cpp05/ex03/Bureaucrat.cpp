/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:57:22 by cperron           #+#    #+#             */
/*   Updated: 2023/10/17 17:07:07 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, uint8_t grade) : _name(name), _grade(grade){
	if (grade < 1)
		throw GradeTooHighExeption();
	else if (grade > 150)
		throw GradeTooLowExeption();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other) {
		_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

const std::string &Bureaucrat::getName() const{
	return _name;
}

const uint8_t &Bureaucrat::getGrade() const{
	return _grade;
}

const char* Bureaucrat::GradeTooLowExeption::what() const throw(){
	return "grade is too low";
}

const char* Bureaucrat::GradeTooHighExeption::what() const throw(){
	return "grade is too high";
}

const char* Bureaucrat::FormNotSignedExeption::what() const throw(){
	return "is not signed";
}

void Bureaucrat::incrementGrade(uint8_t amount){
	if (_grade - amount < 1)
		throw GradeTooHighExeption();
	_grade -= amount;
}

void Bureaucrat::decrementGrade(uint8_t amount){
	if (_grade + amount > 150)
		throw GradeTooLowExeption();
	_grade += amount;
}

void Bureaucrat::signAForm(AForm &Aform) {
	try {
		Aform.beSigned(*this);
		std::cout << getName() << " signed " << Aform.getAFormName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << getName() << " Couldn't sign " << Aform.getAFormName() << " because "<< e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form){
	form.execute(*this);
}

std::ostream& operator<< (std::ostream &out, const Bureaucrat &other) {
	out << other.getName() << ", bureaucrate grade " << static_cast<int>(other.getGrade());
	return out;
}