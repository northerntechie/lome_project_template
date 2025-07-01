/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <tuple>
#include <vector>

namespace Types {

	enum class VertexColor {
		White,
		Gray,
		Black
	};

	enum class EdgeType {
		Tree,
		Backward,
		Forward,
		Cross
	};

	struct Vertex {
		int id = -1;
		bool operator==(const Vertex& other) const;
	};
} // Types namespace