/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:05:54 by cperron           #+#    #+#             */
/*   Updated: 2023/07/31 12:02:39 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap {
protected:
	std::string 		_Name;
	int					_HitPoint;
	int					_EnergyPoint;
	unsigned int		_AttackDamage;
	bool				_HaveHP;
	bool				_HaveEP;
	std::string			_TextColor;
	
	ClapTrap();

public:
	ClapTrap(std::string Name, std::string TextColor);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();

	virtual void someVirtualFunction();
	
	std::string	getName()const;
	int		getHitPoint()const;
	int		getEnergyPoint()const;
	int		getAttackDamage()const;
	bool	haveHP()const;
	bool	haveEP()const;
	
	void		attack(const std::string& target);
	void		attackV2(ClapTrap& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
} ;
