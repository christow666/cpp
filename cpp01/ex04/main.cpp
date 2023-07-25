/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 10:22:14 by cperron           #+#    #+#             */
/*   Updated: 2023/07/20 18:30:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceWord(std::string toChange, std::string newWord, std::string line){
	size_t found;
	std::istringstream iss(line);
	std::ostringstream oss;
	std::string word;
	
	found = line.find(toChange);
	if (found != std::string::npos){
		while (iss >> word) {
			if (word != toChange) {
				oss << word << " ";
			}
		}
		line = oss.str();
		line.insert(found, newWord + " ");
	}
	return(line);
}

int	main(int argc, char **argv){
	
	if (argc == 4){
		std::ifstream file;
		std::string line;
		std::string toChange = argv[2];
		std::string newWord = argv[3];
		std::string fileName = argv[1];
		std::ofstream outputFile(fileName + ".replace");
	
		file.open(fileName);
		if (file.is_open()){
			while (std::getline(file, line)){
				outputFile << replaceWord(toChange, newWord, line) + "\n";
			}
		}
		else {
			std::cout << "Error : couldn't open file." << std::endl;
			return 1;
		}
		outputFile.close();
		file.close();
	}
	else {
		std::cout << "Error : wrong number or args" << std::endl;
		return 1;
	}
	return 0;
}
