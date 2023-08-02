/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:58:48 by cperron           #+#    #+#             */
/*   Updated: 2023/08/02 11:33:58 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
private:
		int _IsAKeeper;

public:
	ScavTrap();
	ScavTrap(std::string name, std::string TextColor);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();

	int	isAKeeper()const;

	void 	decrementIsAKeeper();
	void	guardGate();
} ;
 

