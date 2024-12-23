/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "test/GraphUnitTests.hpp"
#include "test/Utils.hpp"
#include "types/Graph.hpp"

#include <iostream>

namespace Test {
	void Graph_load_OutputCorrect() {
		TEST_HEADER();
		Types::Graph graph;

		graph.load("data/test.json");
		std::cout << "\tOutput: ";
		std::cout << graph;

		assert(graph.isEdge(1,2));
		assert(graph.isEdge(2,3));
		TEST_FOOTER();
	}
} // Test namespace
