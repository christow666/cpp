/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:09:31 by cperron           #+#    #+#             */
/*   Updated: 2023/07/17 18:34:06 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	Weapon &weapon;
	std::string name;
	HumanA();
	
public:
	HumanA(std::string name, Weapon &weapon);
	
	void	attack();
} ;

#endif
