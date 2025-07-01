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
#include "types/Vertex.hpp"
#include "GraphAlgorithms.hpp"

#include <algorithm>

namespace Algo {
	void dfs(const Types::Graph& graph, int s, std::vector<int>& predecessor) {
		std::vector<int> vertices = graph.getVertices();
		std::vector<Types::VertexColor> color(vertices.size());
		std::vector<int> discovered(vertices.size());
		std::vector<int> finished(vertices.size());
		std::size_t counter = 0;

		std::fill(color.begin(), color.end(), Types::VertexColor::White);
		std::fill(discovered.begin(), discovered.end(), -1);
		std::fill(finished.begin(), finished.end(), -1);

		_dfs_visit(graph, discovered, finished, predecessor, color, s, counter);

		for (const auto v : vertices) {
			if (color[v] == Types::VertexColor::White) {
				_dfs_visit(graph, discovered, finished, predecessor, color, v, counter);
			}
		}
	}

	void _dfs_visit(
		const Types::Graph& graph,
		std::vector<int>& discovered,
		std::vector<int>& finished,
		std::vector<int>& predecessor,
		std::vector<Types::VertexColor>& color,
		int id,
		std::size_t counter)
	{
		color[id] = Types::VertexColor::Gray;
		discovered[id] = ++counter;

		for (const auto edge : graph.getConnectedEdges(id)) {
			if (color[edge.second] == Types::VertexColor::White) {
				predecessor[edge.second] = id;
				_dfs_visit(graph, discovered, finished, predecessor, color, edge.second, counter);
			}
		}

		color[id] = Types::VertexColor::Black;
		finished[id] = ++counter;
	}
} // Algo namespace