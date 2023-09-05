/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:29:32 by cperron           #+#    #+#             */
/*   Updated: 2023/08/10 15:15:07 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class ICharacter ;

class AMateria {
private:
	AMateria();

protected:
	std::string _type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria &toher);
	virtual ~AMateria();
	
	std::string const &getType()const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
} ;
