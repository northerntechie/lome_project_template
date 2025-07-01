/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include "test/Utils.hpp"

namespace Test {
	void Graph_load_OutputCorrect();
	void GraphLoad_getConnectedEdges_EdgesCorrect();
	void GraphLoad_removeEdge_EdgesCorrect();
	void GraphLoad_addEdge_EdgesCorrect();
	void Graph_isDirected_Success();
	void Graph_numVertices_Success();
	void Graph_isEdge_Success();
	void Graph_edgeWeight_Success();
	void Graph_getVertices_VerticesCorrect();
} // Test namespace
