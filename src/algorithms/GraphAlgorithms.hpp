/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <vector>

namespace Types {
	class Graph;
	enum class VertexColor;
}
using VertexList = std::vector<std::pair<int,int>>;

namespace Algo {
	void dfs(const Types::Graph& graph, int id, std::vector<int>& predecessor);
	void _dfs_visit(
		const Types::Graph& vertices,
		std::vector<int>& discovered,
		std::vector<int>& finished,
		std::vector<int>& predecessor,
		std::vector<Types::VertexColor>& color,
		int id,
		std::size_t counter);
} // Algo namespace