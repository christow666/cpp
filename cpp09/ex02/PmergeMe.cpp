/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperron <cperron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:00:42 by cperron           #+#    #+#             */
/*   Updated: 2023/11/09 11:20:40 by cperron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

void PmergeMe::ftSort(int argc, char **argv){
	for (int i = 1; i < argc; i++) {
        const char* arg = argv[i];
        for (int j = 0; arg[j] != '\0'; j++) {
            if (!std::isdigit(arg[j])) {
               std::cout << "Bad input : must be a positive integer -> " << arg[j] << std::endl;
			   return ;
            }
        }
	}
	int index = 1;
	std::cout << "Before: " ;
	while (index < argc){
		std::cout << argv[index] << " " ;
		index++;
	}
	std::cout <<std::endl;
	
	clock_t start_time = clock();
	sortVector(argc, argv);
    clock_t end_time = clock();
	double elapsed_time = static_cast<double>(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.0);
	std::cout << "Time to precess a range of " << (argc - 1) 
		<< " elements with the std::vector : " << elapsed_time << " us" << std::endl;
		
	start_time = clock();
	sortDeque(argc, argv);
	end_time = clock();
	elapsed_time = static_cast<double>(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.0);
	std::cout << "Time to precess a range of " << (argc - 1) 
		<< " elements with the std::deque : " << elapsed_time << " us" << std::endl;
}

////////////////////////////////////VECTOR/////////////////////////////////////////


void PmergeMe::mergeSortVector(std::vector<std::pair<int, int> > &duo, int start, int end) {
	if (start >= end)
   		return;
	int middle = start + (end - start) / 2;
	mergeSortVector(duo, start, middle);
	mergeSortVector(duo, middle + 1, end);
	int leftIndex = start;
	int rightIndex = middle + 1;
	std::vector<std::pair<int, int> > mergedduo;
	while (leftIndex <= middle && rightIndex <= end) {
		if (duo[leftIndex].first < duo[rightIndex].first){
			mergedduo.push_back(duo[leftIndex]);
			leftIndex++;
		}
		else {
			mergedduo.push_back(duo[rightIndex]);
			rightIndex++;
		}
	}
	while (leftIndex <= middle) {
		mergedduo.push_back(duo[leftIndex]);
		leftIndex++;
	}
	while (rightIndex <= end){
   		mergedduo.push_back(duo[rightIndex]);
		rightIndex++;
	}
	for (int i = start, j = 0; i <= end; i++, j++)
  		duo[i] = mergedduo[j];
}

void PmergeMe::insertSortVector(std::vector<std::pair<int, int> > &duo, std::vector<int> &result){
	int index = 0;
	while (!duo.empty()){
		int nbr = duo.front().second;
		if (nbr != -1){
			std::vector<int>::iterator it = std::lower_bound(result.begin() + index++, result.end(), nbr);
			result.insert(it, nbr);
		}
		duo.erase(duo.begin());
	}
}

void PmergeMe::sortVector(int argc, char **argv){
	std::vector<std::pair<int, int> > duo;
	duo.reserve(argc / 2);
	int index = 1;
	while (index < argc){
		int number1 = atoi(argv[index]);
		index++;
		if (index < argc){
			int number2 = atoi(argv[index]);
			duo.push_back(std::make_pair(number1, number2));
			index++; 
		}
		else
			duo.push_back(std::make_pair(number1, -1));
	}
	for(std::vector<std::pair<int, int > >::iterator it = duo.begin(); it != duo.end(); ++it) {
		if (it->first > it->second && it->second != -1)
			std::swap(it->first, it->second);
	}
	mergeSortVector(duo, 0, duo.size() - 1); 
	std::vector<int> result;
	result.reserve(argc - 1);
	for(std::vector<std::pair<int, int > >::iterator it = duo.begin(); it != duo.end(); ++it)
			result.push_back(it->first);
	result.push_back(duo.back().second); 
	duo.pop_back();
	insertSortVector(duo, result); 
	std::cout << "After: ";
	for(std::vector<int>::iterator it = result.begin(); it != result.end(); ++it)
			std::cout << *it << " ";
	std::cout << std::endl;
}

/////////////////////////////////////DEQUE////////////////////////////////////////////

void PmergeMe::mergeSortDeque(std::deque<std::pair<int, int> > &duo, int start, int end) {
	if (start >= end)
   		return;
	int middle = start + (end - start) / 2;
	mergeSortDeque(duo, start, middle);
	mergeSortDeque(duo, middle + 1, end);
	int leftIndex = start;
	int rightIndex = middle + 1;
	std::deque<std::pair<int, int> > mergedduo;
	while (leftIndex <= middle && rightIndex <= end) {
		if (duo[leftIndex].first < duo[rightIndex].first){
			mergedduo.push_back(duo[leftIndex]);
			leftIndex++;
		}
		else {
			mergedduo.push_back(duo[rightIndex]);
			rightIndex++;
		}
	}
	while (leftIndex <= middle) {
		mergedduo.push_back(duo[leftIndex]);
		leftIndex++;
	}
	while (rightIndex <= end){
   		mergedduo.push_back(duo[rightIndex]);
		rightIndex++;
	}
	for (int i = start, j = 0; i <= end; i++, j++)
  		duo[i] = mergedduo[j];
}

void PmergeMe::insertSortDeque(std::deque<std::pair<int, int> > &duo, std::deque<int> &result){
	int index = 0;
	while (!duo.empty()){
		int nbr = duo.front().second;
		if (nbr != -1){
			std::deque<int>::iterator it = std::lower_bound(result.begin() + index++, result.end(), nbr);
			result.insert(it, nbr);
		}
		duo.erase(duo.begin());
	}
}

void PmergeMe::sortDeque(int argc, char **argv){
	std::deque<std::pair<int, int> > duo;
	int index = 1;
	while (index < argc){
		int number1 = atoi(argv[index]);
		index++;
		if (index < argc){
			int number2 = atoi(argv[index]);
			duo.push_back(std::make_pair(number1, number2));
			index++; 
		}
		else
			duo.push_back(std::make_pair(number1, -1));
	}
	for(std::deque<std::pair<int, int > >::iterator it = duo.begin(); it != duo.end(); ++it){ // 2nd step
		if (it->first > it->second && it->second != -1)
			std::swap(it->first, it->second);
	}
	mergeSortDeque(duo, 0, duo.size() - 1); 
	std::deque<int> result;
	for(std::deque<std::pair<int, int > >::iterator it = duo.begin(); it != duo.end(); ++it)
			result.push_back(it->first);
	result.push_back(duo.back().second); 
	duo.pop_back();
	insertSortDeque(duo, result); 
	// std::cout << "After: ";
	// for(std::deque<int>::iterator it = result.begin(); it != result.end(); ++it)
	// 		std::cout << *it << " ";
	// std::cout << std::endl;
}

PmergeMe::~PmergeMe(){}

// Insertion Time: Deques are typically faster than vectors when it comes to inserting elements
// in the middle or at the beginning of the container. If your sorting algorithm involves frequent
// insertions or merges in the middle of the container, deques may perform better because they are
// designed to efficiently support these operations.

// Dynamic Memory Allocation: Vectors have a contiguous block of memory, and when they reach their capacity,
// they need to allocate a new, larger block and copy elements over. Deques are implemented as a collection of
// smaller blocks (chunks), which allows them to avoid the reallocation and copying overhead that vectors may incur.
// This can be beneficial in insertion-heavy operations.

// Iterator Stability: Deques have better iterator stability compared to vectors. When you insert or erase
// elements in a vector, it can invalidate existing iterators. Deques, on the other hand, are more forgiving
// in this regard, which can simplify your algorithm's implementation and potentially lead to better performance.

// Element Copying and Moving: The efficiency of copying or moving elements can vary between the two containers.
// If your algorithm frequently moves or copies elements, deques may outperform vectors due to their chunked storage structure.
