/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:33:41 by cperron           #+#    #+#             */
/*   Updated: 2023/11/13 10:03:05 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const RPN& other) {
    _data = other._data;
    _equation = other._equation;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _data = other._data;
        _equation = other._equation;
    }
    return *this;
}

RPN::RPN(std::string equation) : _equation(equation) {}

void RPN::solveEquation(){
	for (std::string::iterator it = _equation.begin(); it != _equation.end(); ++it) {
        char c = *it;
		if (c >= '0' && c <= '9'){
			_data.push(atoi(&c));
		}
		else if (c == ' ')
			continue;
		else if ((c == '-' || c == '+' || c == '*' || c == '/') && _data.size() >= 2){
			int second = _data.top();
			_data.pop();
			int first = _data.top();
			_data.pop();
			if (c == '-')
				_data.push(first - second);
			else if (c == '+')
				_data.push(first + second);
			else if (c == '/'){
				if (second == 0){
					std::cout << "can't devide by 0" << std::endl;
					return ;
				}
				_data.push(first / second);
			}
			else if (c == '*')
				_data.push(first * second);
		}
		else {
			std::cout << "you failed at beeing a good reverse polish notation" << std::endl;
			return ;
		}
    }
	std::cout << _data.top() << std::endl;
}

RPN::~RPN(){}