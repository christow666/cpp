/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:22:05 by cperron           #+#    #+#             */
/*   Updated: 2023/08/13 14:53:32 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure : public AMateria{
public:
	Cure();
	Cure(std::string const &type);
	Cure(const Cure &other);
	Cure& operator=(const Cure &toher);
	virtual ~Cure();
	
	std::string const &getType()const;
	void use(ICharacter& target);
	AMateria* clone() const;
} ;