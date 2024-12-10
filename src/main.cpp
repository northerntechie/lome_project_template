/**
 * Lome sample project
 * Main test application
 * 
 */

#include "Algorithms.hpp"
#include "Math.hpp"
#include "Node.hpp"

#include <iostream>
#include <optional>
#include <string_view>

#define TEST_HEADER std::cout << __FUNCTION__ << "\n";

void test_NodeStringVariant_get_CorrectValue() {
	TEST_HEADER
	Types::Node node("TestString");

	std::optional<std::string> result = node.get<std::string>();

	if (result.has_value()) {
		std::cout << "Result= " << *result << "\n";
	}
	else {
		std::cout << "Test Failed!\n";
	}
}

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
	test_NodeStringVariant_get_CorrectValue();
}