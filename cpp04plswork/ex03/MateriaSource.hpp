/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:49:35 by cperron           #+#    #+#             */
/*   Updated: 2023/09/05 15:18:27 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class IMateriaSource ;

class MateriaSource : public IMateriaSource {
private:
	std::string _type;
	AMateria* _inventory[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource& operator=(const MateriaSource &other);
	~MateriaSource();
	
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const &type);
};
