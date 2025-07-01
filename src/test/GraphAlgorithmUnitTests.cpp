/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "test/GraphAlgorithmUnitTests.hpp"
#include "test/Utils.hpp"
#include "algorithms/GraphAlgorithms.hpp"
#include "algorithms/DepthFirstSearch.hpp"
#include "types/Graph.hpp"

#include <algorithm>
#include <iostream>
#include "GraphAlgorithmUnitTests.hpp"

namespace Test {
	void Graph_dfs_PredecessorsCorrect()
	{
		Types::Graph graph;
		graph.addEdge(0, 1);
		graph.addEdge(1, 2);
		graph.addEdge(2, 3);
		graph.addEdge(2, 6);
		graph.addEdge(0, 4);
		graph.addEdge(4, 5);
		graph.addEdge(4, 3);
		graph.addEdge(3, 2);
		graph.addEdge(8, 7);

		std::vector<int> predecessors(graph.numVertices());
		std::fill(predecessors.begin(), predecessors.end(), -1);
		
		Algo::dfs(graph, 0, predecessors);

		TEST_ASSERT(predecessors == (std::vector<int>{ -1, 0, 1, 2, 0, 4, 2, -1, -1 }), "");
	}

	void Graph_DepthFirstSearch_PredecessorsCorrect()
	{
		Types::Graph graph;
		graph.addEdge(0, 1);
		graph.addEdge(1, 2);
		graph.addEdge(2, 3);
		graph.addEdge(2, 6);
		graph.addEdge(0, 4);
		graph.addEdge(4, 5);
		graph.addEdge(4, 3);
		graph.addEdge(3, 2);
		graph.addEdge(8, 7);
		
		auto predecessors = Algo::DepthFirstSearch{ graph }.search(0);

		TEST_ASSERT(predecessors == (std::vector<int>{ -1, 0, 1, 2, 0, 4, 2, -1, -1 }), "");
	}
} // Test namespace