/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:25:57 by cperron           #+#    #+#             */
/*   Updated: 2023/11/01 09:53:36 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
template <typename T> void swap(T &x , T &y){
	T temp = x;
	x = y;
	y = temp;
}

template <typename T> T min(T const &x, T const &y){
	return (x <= y ? x : y);
}

template <typename T> T max(T const &x, T const &y){
	return (x >= y ? x : y);
}

