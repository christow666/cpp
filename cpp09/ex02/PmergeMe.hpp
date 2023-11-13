/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:30 by cperron           #+#    #+#             */
/*   Updated: 2023/11/13 10:07:47 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <cctype>
#include <ctime>

class PmergeMe {
private:

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &ohter);
	~PmergeMe();

	void ftSort(int argc, char **argv);
	
	void mergeSortVector(std::vector<std::pair<int, int> > &pairs, int start, int end);
	void insertSortVector(std::vector<std::pair<int, int> > &pairs, std::vector<int> &result);
	void sortVector(int argc, char **argv);

	void mergeSortDeque(std::deque<std::pair<int, int> > &pairs, int start, int end);
	void insertSortDeque(std::deque<std::pair<int, int> > &pairs, std::deque<int> &result);
	void sortDeque(int argc, char **argv);
	
} ;