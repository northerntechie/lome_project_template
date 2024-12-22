/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#pragma once

#include "types/Vertex.hpp"
#include <nlohmann/json.hpp>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace Types {
	struct Edge {
		int startId = -1;
		int endId = -1;
		float weight = 1.0f;
		Edge(int startId, int endId, float weight)
		: startId(startId), endId(endId), weight(weight) {}
	};
} // Types namespace