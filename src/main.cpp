/**
 * Lome sample project
 * Main test application
 * 
 */

#include "Algorithms.hpp"
#include "Math.hpp"

#include <iostream>
#include <string_view>

int main()
{
	/**
	 * Algorithms test section
	 */
	std::vector<Data> data0 = {
		{"Alex"}, {"Arthur"}, {"Beatrice"},
		{"Bernie"}, {"Gary"}, {"David"},
		{"Maximillian"}, {"Thomas"}, {"Angie"}};
	
	std::cout << "Before the insert sort operation:\n";
	for (auto& datum : data0) {
		std::cout << datum.name << ", ";
	}

	insertion_sort(data0);

	std::cout << "\nAfter the insert sort operation:\n";
		for (auto& datum : data0) {
		std::cout << datum.name << ", ";
	}

	std::cout << "\n";
}