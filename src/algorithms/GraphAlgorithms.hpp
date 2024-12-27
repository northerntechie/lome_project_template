/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#pragma once

#include <vector>

namespace Types {
	class Graph;
}

namespace Algo {
	int dfs(const Types::Graph& graph, int id);
	void _dfs_visit(const Types::Graph& graph, std::vector<int>& d, std::vector<int>& f, std::vector<int>& pred, int id);
} // Algo namespace