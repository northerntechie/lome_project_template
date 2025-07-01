/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "test/GraphUnitTests.hpp"
#include "test/Utils.hpp"
#include "types/Edge.hpp"
#include "types/Graph.hpp"

#include <iostream>

namespace Test {
	void Graph_load_OutputCorrect() {
		Types::Graph graph;

		graph.load("data/test.json");
		std::cout << "\tOutput: ";
		std::cout << graph;

		TEST_ASSERT(graph.isEdge(1,2), "Edge is incorrect");
		TEST_ASSERT(graph.isEdge(2,3), "Edge is incorrect");
	}

	void GraphLoad_getConnectedEdges_EdgesCorrect()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		auto connectedEdges = graph.getConnectedEdges(1);

		TEST_ASSERT(connectedEdges.size() == 2, "Failed to retrieve the correct number of edges");
		TEST_ASSERT(connectedEdges == (Types::Graph::VertexList{
			std::pair<int,int>{ 1, 2 },
			std::pair<int,int>{ 1, 4 } }), "");
	}

	void GraphLoad_removeEdge_EdgesCorrect()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		bool result = graph.removeEdge(1,2);

		TEST_ASSERT(result, "removeEdge returned false");
		TEST_ASSERT(graph.getVertexPairs() == (Types::Graph::VertexList{
			Types::Graph::IntegerPair{ 2, 3 },
			Types::Graph::IntegerPair{ 1, 4 } }), "");
	}

	void GraphLoad_addEdge_EdgesCorrect()
	{
		Types::Graph graph;

		graph.addEdge(1, 2, 1.0f);
		graph.addEdge(2, 3, 0.5f);

		const auto& edges = graph.getVertexPairs();
		TEST_ASSERT(edges[0] == (Types::Graph::IntegerPair{ 1, 2 }), "");
		TEST_ASSERT(edges[1] == (Types::Graph::IntegerPair{ 2, 3 }), "");
	}

	void Graph_isDirected_Success()
	{
		Types::Graph graph{1, true};

		bool result = graph.isDirected();

		TEST_ASSERT(result, "Graph is not a directed graph");
	}

	void Graph_numVertices_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		int result = graph.numVertices();

		TEST_ASSERT(result == 4, "Size of graph is not correct");
	}

	void Graph_isEdge_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		bool result = graph.isEdge(1,2);

		TEST_ASSERT(result, "isEdge failed");
	}

	void Graph_edgeWeight_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		const float result = graph.edgeWeight(1,2);

		TEST_ASSERT(result == 1.0f, "edgeWeight Success");
	}

	void Graph_getVertices_VerticesCorrect()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		const std::vector<int> result = graph.getVertices();

		TEST_ASSERT(result == (std::vector<int>{
			1, 2, 3, 4
		}), "Vertices set is not correct");
	}
} // Test namespace
