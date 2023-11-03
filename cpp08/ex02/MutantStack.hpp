/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:24:57 by cperron           #+#    #+#             */
/*   Updated: 2023/11/03 10:47:34 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
	MutantStack(){};
	MutantStack(const MutantStack &other) { 
		*this = other; 
	};
	MutantStack &operator=(const MutantStack &other) { 
		(void)other;
		return *this;
	}
	~MutantStack(){};

	
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }

    const_iterator begin() const {
        return this->c.begin();
    }

    const_iterator end() const {
        return this->c.end();
    }

    reverse_iterator rbegin() {
        return this->c.rbegin();
    }

    reverse_iterator rend() {
        return this->c.rend();
    }

    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }

    const_reverse_iterator rend() const {
        return this->c.rend();
    }

};