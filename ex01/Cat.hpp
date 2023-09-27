/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:12:46 by cperron           #+#    #+#             */
/*   Updated: 2023/09/21 18:30:17 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
private:
	Brain* _brain;
	
protected:
	std::string _type;
	
public:
	Cat();
	Cat(std::string const& type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	virtual ~Cat();
	
	void makeSound() const;
	const std::string* getCatIdea() const;
	const Brain* getBrain()const;
} ;