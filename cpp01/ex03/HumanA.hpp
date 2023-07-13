/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:09:31 by cperron           #+#    #+#             */
/*   Updated: 2023/07/12 23:15:21 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
private:
	Weapon weapon;
	std::string name;
	
public:
	HumanA();
	HumanA(std::string name, Weapon weapon);
	
	void	attack();
} ;

#endif
