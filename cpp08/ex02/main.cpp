/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:17:11 by cperron           #+#    #+#             */
/*   Updated: 2023/11/03 11:23:53 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <iterator>
#include <list>
#include "MutantStack.hpp"

void mutantTest(){
	// Mutant test
	std::cout << "Mutant --------------------------------" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Last added : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Current size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	std::cout << "Iterator: " << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << " " ;
		// *it = 2; // not constant so we can change
		++it;
	}
	std::cout << std::endl;

	std::cout << "Constant iterator: " << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();
	++cit;
    --cit;
	while (cit != cite){
        std::cout << *cit << " " ;
		// *cit = 2; // constant so won't compile
        ++cit;
    }
	std::cout << std::endl;
	
	std::cout << "Reverse iterator: " << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite){
        std::cout << *rit << " " ;
		// *rit = 2; // not constant so we can change
        ++rit;
    }
	std::cout << std::endl;

	std::cout << "Constant reverse iterator: " << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();
    ++crit;
    --crit;
    while (crit != crite){
        std::cout << *crit << " " ;
		// *crit = 2; // constant so won't compile
        ++crit;
    }
	std::cout << std::endl;
	
	std::stack<int> s(mstack);
	std::cout << std::endl;
}

int main() {
	mutantTest();
	
	// list test
	std::cout << "List --------------------------------" << std::endl;

	std::list<int> lstack;
	lstack.push_back(5);
	lstack.push_back(17);
	std::cout << "Last added  : " << lstack.back() << std::endl;
	lstack.pop_back();
	std::cout << "Current size : " << lstack.size() << std::endl;
	lstack.push_back(3);
	lstack.push_back(5);
	lstack.push_back(737);
	//[...]
	lstack.push_back(0);
	
	std::cout << "Iterator: " << std::endl;
	std::list<int>::iterator it = lstack.begin();
	std::list<int>::iterator ite = lstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << " " ;
		// *it = 2; // not constant so we can change
		++it;
	}
	std::cout << std::endl;

	std::cout << "Constant iterator: " << std::endl;
    std::list<int>::const_iterator cit = lstack.begin();
    std::list<int>::const_iterator cite = lstack.end();
	++cit;
    --cit;
	while (cit != cite){
        std::cout << *cit << " " ;
		// *cit = 2; // constant so won't compile
        ++cit;
    }
	std::cout << std::endl;
	
	std::cout << "Reverse iterator: " << std::endl;
    std::list<int>::reverse_iterator rit = lstack.rbegin();
    std::list<int>::reverse_iterator rite = lstack.rend();
    ++rit;
    --rit;
    while (rit != rite){
        std::cout << *rit << " " ;
		// *rit = 2; // not constant so we can change
        ++rit;
    }
	std::cout << std::endl;

	std::cout << "Constant reverse iterator: " << std::endl;
    std::list<int>::const_reverse_iterator crit = lstack.rbegin();
    std::list<int>::const_reverse_iterator crite = lstack.rend();
    ++crit;
    --crit;
    while (crit != crite){
        std::cout << *crit << " " ;
		// *crit = 2; // constant so won't compile
        ++crit;
    }
	std::cout << std::endl;
	
	std::list<int> s(lstack);
	std::cout << std::endl;

	return 0;
}