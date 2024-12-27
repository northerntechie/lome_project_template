/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "test/GraphUnitTests.hpp"
#include "test/Utils.hpp"
#include "types/Edge.hpp"
#include "types/Graph.hpp"

#include <iostream>
#include "GraphUnitTests.hpp"

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
		TEST_ASSERT(connectedEdges == (std::vector<Types::Edge>{ Types::Edge{1, 2, 1.0f}, Types::Edge{1, 4, 1.0f} }), "");
	}

	void GraphLoad_removeEdge_EdgesCorrect()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		bool result = graph.removeEdge(1,2);

		assert(result && "removeEdge returned false");
		assert(graph.getEdges() == (std::vector<Types::Edge>{ Types::Edge{2, 3, 0.5f}, Types::Edge{1, 4, 1.0f} }));
	}

	void GraphLoad_addEdge_EdgesCorrect()
	{
		Types::Graph graph;

		graph.addEdge(1, 2, 1.0f);
		graph.addEdge(2, 3, 0.5f);

		const auto& edges = graph.getEdges();
		assert(edges[0] == Types::Edge(1, 2, 1.0f));
		assert(edges[1] == Types::Edge(2, 3, 0.5f));
	}

	void Graph_isDirected_Success()
	{
		Types::Graph graph{1, true};

		bool result = graph.isDirected();

		assert(result && "Graph is not a directed graph");
	}

	void Graph_numEdges_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		int result = graph.numEdges();

		assert(result == 3 && "Size of graph is not correct");
	}

	void Graph_isEdge_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		bool result = graph.isEdge(1,2);

		assert(result && "isEdge failed");
	}

	void Graph_edgeWeight_Success()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		const float result = graph.edgeWeight(1,2);

		assert(result == 1.0f && "edgeWeight Success");
	}

	void Graph_getVertices_VerticesCorrect()
	{
		Types::Graph graph;
		graph.load("data/test.json");

		const std::set<int> result = graph.getVertices();

		assert(result == (std::set<int>{
			1, 2, 3, 4
		}) && "Vertices set is not correct");
	}
} // Test namespace
