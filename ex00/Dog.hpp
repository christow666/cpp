/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:12:46 by cperron           #+#    #+#             */
/*   Updated: 2023/08/09 12:49:00 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal{
protected:
	std::string _type;
	
public:
	Dog();
	Dog(std::string const& type);
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();
	
	void makeSound() const;
} ;