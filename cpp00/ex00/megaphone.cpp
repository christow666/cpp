/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:14:39 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 14:39:09 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string	concatenateStrings(int argc, char **argv){
	std::string message = argv[1];
	for (int i = 2; i < argc; i++){
		message += argv[i];
	}
	return (message);
}

void	megaphone(const std::string& outputMessage){
	std::string upperMessage = outputMessage;
	for (int i = 0; upperMessage[i]; i++){
		upperMessage[i] = std::toupper(upperMessage[i]);
	}
	std::cout << upperMessage <<std::endl;
}

int	main(int argc, char** argv){
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	std::string outputMessage = concatenateStrings(argc, argv);
	megaphone(outputMessage);
	return 0;
}