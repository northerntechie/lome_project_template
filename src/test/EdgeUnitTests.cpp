/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "test/EdgeUnitTests.hpp"
#include "test/Utils.hpp"
#include "types/Edge.hpp"

namespace Test {
	void DuplicatedEdges_isUnique_ReturnFalse() {
		Types::Edge edge0{1, 2, 1.0f};
		Types::Edge edge1{1, 2, 1.0f};

		bool result = edge0.isUnique(edge1);

		assert(!result && "isUnique should return false for duplicate edges");
	}

	void TwoDistinctEdges_isUnique_ReturnTrue() {
		Types::Edge edge0{1, 2, 1.0f};
		Types::Edge edge1{2, 3, 1.0f};

		bool result = edge0.isUnique(edge1);

		assert(result && "isUnique should return true for unique edges");
	}

	void TwoDuplicatedEdgesDifferentWeight_isUnique_ReturnFalse() {
		Types::Edge edge0{1, 2, 0.5f};
		Types::Edge edge1{1, 2, 1.0f};

		bool result = edge0.isUnique(edge1);

		assert(!result && "isUnique should return false for duplicate edges with different weights");
	}
} // Test namespace