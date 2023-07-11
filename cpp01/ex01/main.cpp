/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christo <christo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 00:07:03 by christo           #+#    #+#             */
/*   Updated: 2023/07/11 00:19:17 by christo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main() {
	int N = 10;
	Zombie *zombieHord = zombieHorde(N, "tremblay");
	Zombie *zombieHord1 = zombieHorde(N, "bozo");

	for (int i = 0; i < N; i++) {
		zombieHord[i].annouce();
		zombieHord1[i].annouce();
    }
	delete [] zombieHord;
	delete [] zombieHord1;
	return 0;
}