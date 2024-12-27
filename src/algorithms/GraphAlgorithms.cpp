/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "algorithms/GraphAlgorithms.hpp"
#include "types/Graph.hpp"
#include "GraphAlgorithms.hpp"

namespace Algo {
	int dfs(const Types::Graph& graph, int s) {
		std::set<int> vertices = graph.getVertices();

		for (const int v : vertices) {

		}
		return -1;
	}

	
	void _dfs_visit(const Types::Graph& graph, std::vector<int>& d, std::vector<int>& f, std::vector<int>& pred, int id)
	{
		
	}
} // Algo namespace