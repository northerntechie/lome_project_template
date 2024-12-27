/**
 * Lome sample project
 * Main test application
 * 
 */

#include "algorithms/Algorithms.hpp"
#include "Math.hpp"
#include "test/TestRunner.hpp"

#include <iostream>
#include <optional>
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

	std::cout << "\n\n";

	/*
	* Unit tests
	*/
	std::cout << "Unit tests:\n";
	Test::runUnitTests();
}