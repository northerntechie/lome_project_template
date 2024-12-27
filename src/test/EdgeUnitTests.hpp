#pragma once

#include "test/Utils.hpp"

namespace Test {
	void DuplicatedEdges_isUnique_ReturnFalse();
	void TwoDistinctEdges_isUnique_ReturnTrue();
	void TwoDuplicatedEdgesDifferentWeight_isUnique_ReturnFalse();
} // Test namespace
