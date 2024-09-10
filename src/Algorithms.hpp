/**
 * Lome sample project - Algorithms
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <vector>
#include <string_view>

struct Data {
	std::string_view name;
	bool operator>(Data& other) {
		return name > other.name;
	}
};

// Insert Sort Algorithm
void insert(std::vector<Data>& arr, std::size_t pos, Data& value);
void insertion_sort(std::vector<Data>& arr);

// 
