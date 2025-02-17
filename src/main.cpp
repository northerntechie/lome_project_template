/**
 * Lome sample project
 * Main test application
 * 
 */
#include "test/TestRunner.hpp"

#include <iostream>


int main()
{
	/*
	* Unit tests
	*/
	std::cout << "Unit tests:\n";
	Test::runUnitTests();
}