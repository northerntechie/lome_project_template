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
#include <set>
#include <span>

namespace Types {

	class Graph {
	private:
		int maxVertices = 16;
		bool directed = false;
		std::vector<Edge> edges;

		std::vector<Edge>::const_iterator _findEdge(int u, int v) const;
		void _updateEdges();

	public:
		Graph() = default;
		Graph(int maxVertices, bool directed = false);
		~Graph() = default;

		bool load(std::string_view fileName);
		bool isDirected() const;
		int numEdges() const;
		bool isEdge(int u, int v) const;
		float edgeWeight(int u, int v) const;
		bool addEdge(int u, int v, float weight = 1.0f);
		bool removeEdge(int u, int v);
		const std::vector<Edge>& getEdges() const;
		std::vector<Edge> getConnectedEdges(int u) const;
		std::set<int> getVertices() const;
		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
	};
} // namespace Types

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Types::Edge, u, v, weight)
