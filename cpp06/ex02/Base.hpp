/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:34:40 by cperron           #+#    #+#             */
/*   Updated: 2023/10/15 16:46:25 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {
public:
	virtual ~Base();
	
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);
};