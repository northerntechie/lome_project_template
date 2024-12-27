/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#include "Graph.hpp"

#include <nlohmann/json.hpp>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>

namespace Types {

		std::ostream& operator<<(std::ostream& os, const Graph& graph) {
		if (graph.edges.empty()) {
			return os;
		}

		os << "{ ";
		for (const auto& edge : graph.edges) {
			os << "(" << edge.u << ",";
			os << edge.v << "," << edge.weight << "),";
		}
		return os << " }\n";
	}

	Graph::Graph(int maxVertices, bool directed /*= false*/)
	: maxVertices(maxVertices), directed(directed) {
		edges.reserve(maxVertices);
	}

	bool Graph::load(std::string_view fileName)
	{
		// TODO(Todd): Implementation needed
		std::fstream fs;
		fs.open(static_cast<const char*>(fileName.data()), std::ios::in);
		if (!fs.is_open()) {
			std::string msg = "Failed to open file: " + std::string(fileName.data());
			assert(false && msg.c_str());
			return false;
		}

		nlohmann::json data = nlohmann::json::parse(fs);
		unsigned int numEdges = 0;
		for (auto it : data) {
			edges.emplace_back(it["u"].get<int>(), it["v"].get<int>(), it["weight"].get<float>());
			++numEdges;
		}

		return true;
	}

	bool Graph::isDirected() const
	{
		return directed;
	}

	int Graph::numEdges() const
	{
		return edges.size();
	}

	bool Graph::isEdge(int u, int v) const
	{
		auto it = _findEdge(u,v);
		return it != edges.end();
	}

	float Graph::edgeWeight(int u, int v) const
	{
		auto it = _findEdge(u, v);
		if (it != edges.end()) {
			return it->weight;
		}
	
		assert(false && "Edge does not exist");
		return 0.0f;
	}

	bool Graph::addEdge(int u, int v, float weight)
	{
		auto it = _findEdge(u, v);
		if (it != edges.end()) {
			assert(false && "Duplication edge found in graph!");

			return false;
		}
		edges.emplace_back(u,v,weight);

		return true;
	}

	bool Graph::removeEdge(int u, int v)
	{
		auto it = _findEdge(u, v);

		if (it != edges.end()) {
			edges.erase(it);

			return true;
		}

		return false;
	}

	const std::vector<Edge>& Graph::getEdges() const
	{
		return edges;
	}

	std::vector<Edge> Graph::getConnectedEdges(int u) const
	{
		std::vector<Edge> result;
		result.reserve(edges.size());

		for (const auto& edge : edges) {
			if (edge.u == u) {
				result.emplace_back(edge.u, edge.v, edge.weight);
			}
		}

		return result;
	}

	std::set<int> Graph::getVertices() const
	{
		std::set<int> vertices;

		for (const auto& edge : edges) {
			vertices.insert(edge.u);
			vertices.insert(edge.v);
		}

		return vertices;
	}

	std::vector<Edge>::const_iterator Graph::_findEdge(int u, int v) const
	{
		return std::find_if(edges.begin(), edges.end(), [u,v](const auto& edge) {
			return edge.u == u && edge.v == v;
		});
	}
} // Types namespace
