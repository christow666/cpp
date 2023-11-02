/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:42:54 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 09:17:19 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(){
	std::vector<int> myvector;
  	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);
	for (int i = 0; i < 5; i++)
		std::cout << myvector[i] << std::endl;
	std::vector<int>::iterator it = easyfind(myvector, 5);
	if (it == myvector.end())
		std::cout << "value not found" << std::endl;
	else
		std::cout << "found "<< *it << std::endl;
	
	std::vector<int>::iterator it2 = easyfind(myvector, 69);
	if (it2 == myvector.end())
		std::cout << "value not found" << std::endl;
	else
		std::cout << "found "<< *it2 << std::endl;
		
	return 0;
}
