/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 10:19:05 by cperron           #+#    #+#             */
/*   Updated: 2023/09/21 15:52:14 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain {
private:
	std::string _ideas[100];
	
public:

	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& other);
	~Brain();
	
	const std::string*  getIdeas() const;
	
} ;