/**
 * Lome sample project - Algorithms
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "Algorithms.hpp"
#include "types/Data.hpp"

namespace Algorithm {
	void insert(std::vector<Data>& arr, std::size_t pos, Data& value)
	{
		std::size_t i = pos - 1;

		while ( (i >= 0) && (arr[i] > value) ) {
			arr[i + 1] = arr[i];
			--i;
		}

		arr[i + 1] = value;
	}

	void insertion_sort(std::vector<Data>& arr)
	{
		for (std::size_t i=1; i < arr.size(); ++i) {
			insert(arr, i, arr[i]);
		}
	}
} // Algorithm namespace
