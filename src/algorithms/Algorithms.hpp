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

struct Data;

namespace Algorithm {
	// Insert Sort Algorithm
	void insert(std::vector<Data>& arr, std::size_t pos, Data& value);
	void insertion_sort(std::vector<Data>& arr);

	// 
} // Algorithm namespace
