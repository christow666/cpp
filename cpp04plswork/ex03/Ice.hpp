/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:07:38 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 01:11:02 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice : public AMateria{
public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice &other);
	Ice& operator=(const Ice &toher);
	virtual ~Ice();
	
	std::string const &getType()const;
	void use(ICharacter& target);
	AMateria* clone() const;
} ;