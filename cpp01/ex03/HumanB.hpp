/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:09:31 by cperron           #+#    #+#             */
/*   Updated: 2023/07/17 19:18:54 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	HumanB();
	Weapon *weapon;
	
public:
	HumanB(const std::string& name);
	
	void 	setWeapon(Weapon &weapon);
	void	attack() const;
} ;

#endif
