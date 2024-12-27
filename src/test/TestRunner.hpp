/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#pragma once

#include "test/GraphUnitTests.hpp"
#include "test/EdgeUnitTests.hpp"
#include "test/Utils.hpp"

namespace Test {
	TEST_METHOD(Graph_load_OutputCorrect);
	TEST_METHOD(GraphLoad_getConnectedEdges_EdgesCorrect);
	TEST_METHOD(GraphLoad_removeEdge_EdgesCorrect);
	TEST_METHOD(GraphLoad_addEdge_EdgesCorrect);
	TEST_METHOD(Graph_isDirected_Success);
	TEST_METHOD(Graph_numEdges_Success);
	TEST_METHOD(Graph_isEdge_Success);
	TEST_METHOD(Graph_edgeWeight_Success);
	TEST_METHOD(DuplicatedEdges_isUnique_ReturnFalse);
	TEST_METHOD(TwoDistinctEdges_isUnique_ReturnTrue);
	TEST_METHOD(TwoDuplicatedEdgesDifferentWeight_isUnique_ReturnFalse);
	TEST_METHOD(Graph_getVertices_VerticesCorrect);

	void runUnitTests() {
		Graph_load_OutputCorrect_TestImpl();
		GraphLoad_getConnectedEdges_EdgesCorrect_TestImpl();
		GraphLoad_removeEdge_EdgesCorrect_TestImpl();
		GraphLoad_addEdge_EdgesCorrect_TestImpl();
		Graph_isDirected_Success_TestImpl();;
		Graph_numEdges_Success_TestImpl();
		Graph_isEdge_Success_TestImpl();
		Graph_edgeWeight_Success_TestImpl();
		DuplicatedEdges_isUnique_ReturnFalse_TestImpl();
		TwoDistinctEdges_isUnique_ReturnTrue_TestImpl();
		TwoDuplicatedEdgesDifferentWeight_isUnique_ReturnFalse_TestImpl();
		Graph_getVertices_VerticesCorrect_TestImpl();
	}
} // Test namespace