/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:43:12 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 20:09:28 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RandomColor.hpp"

int	main(){
	std::string	string = "HI THIS IS BRAIN";
	std::string* stringPTR = &string;
	std::string& stringREF = string;
	
	RandomColors line;

	std::cout << line.getBackColor() << line.getTextColor() << "string adress : "  << &string << Reset << std::endl;
	std::cout << line.getBackColor() << line.getTextColor() << "stringPTR adress : " << &stringPTR << Reset << std::endl;
	std::cout << line.getBackColor() << line.getTextColor() << "stringREF adress : " << &stringREF << Reset << std::endl;
	std::cout << std::endl;
	std::cout << line.getBackColor() << line.getTextColor() << "string value : " << string << Reset << std::endl;
	std::cout << line.getBackColor() << line.getTextColor() << "stringPTR value : " << *stringPTR << Reset << std::endl;
	std::cout << line.getBackColor() << line.getTextColor() << "stringREF value : " << stringREF << Reset << std::endl;
	return(0);
}