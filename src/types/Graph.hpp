/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include "types/Vertex.hpp"
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Types {
	class Graph {
	private:
		struct Edge {
			int startId = -1;
			int endId = -1;
			float weight = 1.0f;
			Edge(int startId, int endId, float weight)
			: startId(startId), endId(endId), weight(weight) {}
		};

		int maxVertices = 16;
		bool directed = false;
		std::vector<Edge> edges;

	public:
		Graph() = default;
		Graph(int maxVertices, bool directed = false);
		~Graph() = default;

		void load(std::string_view file);
		bool isDirected() const;
		int numVertices() const;
		bool isEdge(int u, int v) const;
		float edgeWeight(int u, int v) const;
		bool addEdge(int u, int v, float weight = 1.0f);
		bool removeEdge(int u, int v);
	};
} // namespace Types
