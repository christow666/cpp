/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:57:41 by cperron           #+#    #+#             */
/*   Updated: 2023/07/24 19:41:20 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>

class Karen {
private:
	std::string level_array[4];
	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	
public:
	void	complain(std::string level);
	Karen();
	~Karen();
} ;
#endif
