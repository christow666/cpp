/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:14:13 by cperron           #+#    #+#             */
/*   Updated: 2023/11/02 15:56:26 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
#include <list>
#define RED "\033[31m"
#define DEF "\033[0m"

using std::cout;
using std::list;
using std::string;
using std::vector;
void mutantStackTest()
{
    cout << RED << "MutantStack Test: " << DEF << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "first:    " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size:     " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    cout << "Iterator: " << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    cout << "Reverse iterator: " << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    cout << "Constant iterator: " << std::endl;
    MutantStack<int>::const_iterator cit = mstack.begin();
    MutantStack<int>::const_iterator cite = mstack.end();

    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *cit = 2;
        ++cit;
    }

    cout << "Constant reverse iterator: " << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = mstack.rend();

    ++crit;
    --crit;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *crit = 2;
        ++crit;
    }
    std::stack<int> s(mstack);
    cout << std::endl;
}

void listTest()
{
    cout << RED << "List Test:" << DEF << std::endl;
    list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "first:    " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "size:     " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    cout << "Iterator: " << std::endl;
    list<int>::iterator it = lst.begin();
    list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    cout << "Reverse iterator: " << std::endl;
    list<int>::reverse_iterator rit = lst.rbegin();
    list<int>::reverse_iterator rite = lst.rend();

    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    cout << "Constant iterator: " << std::endl;
    list<int>::const_iterator cit = lst.begin();
    list<int>::const_iterator cite = lst.end();

    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *cit = 2;
        ++cit;
    }

    cout << "Constant reverse iterator: " << std::endl;
    list<int>::const_reverse_iterator crit = lst.rbegin();
    list<int>::const_reverse_iterator crite = lst.rend();

    ++crit;
    --crit;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *crit = 2;
        ++crit;
    }
    list<int> s(lst);
    cout << std::endl;
}

void vectorTest()
{
    cout << RED << "Vector Test:" << DEF << std::endl;
    vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);
    std::cout << "first:    " << vec.back() << std::endl;
    vec.erase(vec.end() - 1);
    std::cout << "size:     " << vec.size() << std::endl;   
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);
    cout << "Iterator: " << std::endl;
    vector<int>::iterator it = vec.begin();
    vector<int>::iterator ite = vec.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    cout << "Reverse iterator: " << std::endl;
    vector<int>::reverse_iterator rit = vec.rbegin();
    vector<int>::reverse_iterator rite = vec.rend();

    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    cout << "Constant iterator: " << std::endl;
    vector<int>::const_iterator cit = vec.begin();
    vector<int>::const_iterator cite = vec.end();

    ++cit;
    --cit;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *cit = 2;
        ++cit;
    }

    cout << "Constant reverse iterator: " << std::endl;
    vector<int>::const_reverse_iterator crit = vec.rbegin();
    vector<int>::const_reverse_iterator crite = vec.rend();

    ++crit;
    --crit;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        // Uncomenting the next line should give a compilation error since the iterator is constant, no modif allowed.
        // *crit = 2;
        ++crit;
    }
    vector<int> s(vec);
}

int main()
{
    mutantStackTest();
    listTest();
    vectorTest();
    return 0;
}