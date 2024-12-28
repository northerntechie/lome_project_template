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

namespace Algo {
	void dfs(const Types::Graph& graph, int s, std::vector<int>& predecessor) {
		std::vector<int> vertices = graph.getVertices();
		std::vector<Types::VertexColor> color;
		std::vector<int> discovered;
		std::vector<int> finished;
		std::size_t counter = 0;

		for (const auto v : vertices) {
			color[v] = Types::VertexColor::White;
			discovered[v] = -1;
			finished[v] = -1;
			predecessor[v] = -1;
		}
		_dfs_visit(graph, discovered, finished, predecessor, color, vertices[0], counter);

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
			if (color[edge.first] == Types::VertexColor::White) {
				predecessor[edge.first] = id;
				_dfs_visit(graph, discovered, finished, predecessor, color, edge.first, counter);
			}
		}

		color[id] = Types::VertexColor::Black;
		finished[id] = ++counter;
	}
} // Algo namespace