/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:55:08 by cperron           #+#    #+#             */
/*   Updated: 2023/07/17 18:44:02 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon {
private:
	std::string type;
	Weapon();
	
public:
	Weapon(std::string type);
	
	const std::string&	getType();
	void	setType(std::string type);
} ;

#endif
