/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:27:38 by cperron           #+#    #+#             */
/*   Updated: 2023/11/13 10:04:05 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

class RPN {
private:
	std::stack<int> _data;
	std::string _equation;
	RPN();
	
public:
	RPN(std::string equation);
	RPN(const RPN& other);
	RPN &operator=(const RPN& other);
	~RPN();

	void solveEquation();
} ;