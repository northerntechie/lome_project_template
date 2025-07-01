/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 *
 */
#pragma once

#include "types/Vertex.hpp"
#include <nlohmann/json.hpp>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Types {
	struct Edge {
		int u = -1;
		int v = -1;
		float weight = 1.0f;
		Edge(int u, int v, float weight)
		: u(u), v(v), weight(weight) {}

		bool isUnique(const Edge& other) const {
			return u != other.u || v != other.v;
		}

		bool operator==(const Edge& other) const {
			return u == other.u && v == other.v && weight == other.weight;
		}
	};
} // Types namespace
