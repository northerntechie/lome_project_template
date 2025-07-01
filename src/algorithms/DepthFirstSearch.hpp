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
	class DepthFirstSearch {
	public:
		explicit DepthFirstSearch(const Types::Graph& graph);

		std::vector<int> search(int start) const;
	private:
		const Types::Graph& graph;
	};
} // Algo namespace