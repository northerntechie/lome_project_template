/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "algorithms/DepthFirstSearch.hpp"
#include "algorithms/GraphAlgorithms.hpp"
#include "types/Graph.hpp"

namespace Algo {
	DepthFirstSearch::DepthFirstSearch(const Types::Graph &graph)
	: graph(graph) {}

	std::vector<int> DepthFirstSearch::search(int start) const
	{
		std::vector<int> predecessors(graph.numVertices());
		std::fill(predecessors.begin(), predecessors.end(), -1);
		
		dfs(graph, start, predecessors);

		return predecessors;
	}
} // Algo namespace
