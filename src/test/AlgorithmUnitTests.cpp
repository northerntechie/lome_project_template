/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "test/AlgorithmUnitTests.hpp"
#include "algorithms/Algorithms.hpp"
#include "types/Data.hpp"
#include "test/Utils.hpp"

namespace Test {
	void List_Insertion_ListSorted() {
		std::vector<Data> originalData = {
			{"Alex"}, {"Arthur"}, {"Beatrice"},
			{"Bernie"}, {"Gary"}, {"David"},
			{"Maximillian"}, {"Thomas"}, {"Angie"}};
		std::vector<Data> expectedData = {
			{"Alex"}, {"Angie"}, {"Arthur"}, {"Beatrice"},
			{"Bernie"}, {"Gary"}, {"David"},
			{"Indiana"}, {"Maximillian"}, {"Thomas"}};
		Data insertData = { "Indiana" };

		Algorithm::insert(originalData, 3, insertData);

		std::cout << stringifyVector(originalData) << "\n";
		TEST_ASSERT(originalData == expectedData, "List is not sorted correctly");
	}
} // Test namespace
