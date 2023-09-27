/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:30:56 by cperron           #+#    #+#             */
/*   Updated: 2023/09/23 16:55:47 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < 100; ++i) {
            _ideas[i] = "Idea " + std::to_string(i + 1);
	}
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
}

Brain& Brain::operator=(const Brain& other){
	if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = other._ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(){}

const std::string* Brain::getIdeas() const {
	return _ideas;
}

