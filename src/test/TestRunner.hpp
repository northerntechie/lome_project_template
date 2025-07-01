/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include "test/AlgorithmUnitTests.hpp"
#include "test/GraphAlgorithmUnitTests.hpp"
#include "test/GraphUnitTests.hpp"
#include "test/EdgeUnitTests.hpp"
#include "test/TaskManagerUnitTests.hpp"
#include "test/Utils.hpp"

namespace Test {

	void runUnitTests() {
		REGISTER_TEST(Graph_load_OutputCorrect);
		REGISTER_TEST(GraphLoad_getConnectedEdges_EdgesCorrect);
		REGISTER_TEST(GraphLoad_removeEdge_EdgesCorrect);
		REGISTER_TEST(GraphLoad_addEdge_EdgesCorrect);
		REGISTER_TEST(Graph_isDirected_Success);;
		REGISTER_TEST(Graph_numVertices_Success);
		REGISTER_TEST(Graph_isEdge_Success);
		REGISTER_TEST(Graph_edgeWeight_Success);
		REGISTER_TEST(DuplicatedEdges_isUnique_ReturnFalse);
		REGISTER_TEST(TwoDistinctEdges_isUnique_ReturnTrue);
		REGISTER_TEST(TwoDuplicatedEdgesDifferentWeight_isUnique_ReturnFalse);
		REGISTER_TEST(Graph_getVertices_VerticesCorrect);
		REGISTER_TEST(Graph_dfs_PredecessorsCorrect);
		REGISTER_TEST(Graph_DepthFirstSearch_PredecessorsCorrect);
		//REGISTER_TEST(List_Insertion_ListSorted);
		REGISTER_TEST(CreateTaskManager_runTaskCompletedWait_CompletedConfirmed);

		for ([[maybe_unused]] auto& [ name, test] : testFunctions) {
			test();
		}
	}
} // Test namespace