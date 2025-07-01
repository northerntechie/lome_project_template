/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 *
 */
#pragma once

#include "types/Edge.hpp"
#include <nlohmann/json.hpp>
#include <functional>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <set>
#include <span>

namespace std {
    template <>
    struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const noexcept {
			static constexpr size_t HALF_BITSIZET = sizeof(size_t) * 4;
            return size_t((std::hash<int>{}(p.first) << HALF_BITSIZET)) + std::hash<int>{}(p.second);
        }
    };
}

namespace Types {

	class Graph {
	public:
		using IntegerPair = std::pair<int,int>;
		using VertexList = std::vector<IntegerPair>;
		using WeightList = std::unordered_map<IntegerPair, float>;

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
		VertexList getConnectedEdges(int u) const;
		VertexList getVertexPairs() const;
		std::vector<int> getVertices() const;
		friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

	private:
		int maxVertices = 16;
		bool directed = false;
		VertexList vertices;
		WeightList weights;

		VertexList::const_iterator _findEdge(int u, int v) const;
		void _updateEdges();
	};
} // namespace Types

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Types::Edge, u, v, weight)
