/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#pragma once

#include "types/Edge.hpp"
#include <nlohmann/json.hpp>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Types {

	class Graph {
	private:
		int maxVertices = 16;
		bool directed = false;
		std::vector<Edge> edges;

	public:
		Graph() = default;
		Graph(int maxVertices, bool directed = false);
		~Graph() = default;

		bool load(std::string_view fileName);
		bool isDirected() const;
		int numVertices() const;
		bool isEdge(int u, int v) const;
		float edgeWeight(int u, int v) const;
		bool addEdge(int u, int v, float weight = 1.0f);
		bool removeEdge(int u, int v);
		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	};
} // namespace Types

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Types::Edge, startId, endId, weight)
