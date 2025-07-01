/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "Graph.hpp"

#include <nlohmann/json.hpp>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>

namespace Types {

		std::ostream& operator<<(std::ostream& os, const Graph& graph) {
		if (graph.vertices.empty()) {
			return os;
		}

		os << "{ ";
		for (const auto& edge : graph.vertices) {
			os << "(" << edge.first << ",";
			os << edge.second << "),";
		}
		return os << " }\n";
	}

	Graph::Graph(int maxVertices, bool directed /*= false*/)
	: maxVertices(maxVertices), directed(directed) {
		vertices.reserve(maxVertices);
	}

	bool Graph::load(std::string_view fileName)
	{
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
			int u = it["u"].get<int>();
			int v = it["v"].get<int>();
			vertices.emplace_back(u, v);
			weights[std::pair<int,int>(u,v)] = it["weight"].get<float>();
			++numEdges;
		}

		return true;
	}

	bool Graph::isDirected() const
	{
		return directed;
	}

	int Graph::numVertices() const
	{
		std::set<int> uniqueVertices;

		for (const auto& [u, v] : vertices) {
			uniqueVertices.insert(u);
			uniqueVertices.insert(v);
		}

		return uniqueVertices.size();
	}

	bool Graph::isEdge(int u, int v) const
	{
		auto it = _findEdge(u, v);

		return it != vertices.end();
	}

	float Graph::edgeWeight(int u, int v) const
	{
		return 1.0f;
	}

	bool Graph::addEdge(int u, int v, float weight /*=1.0f*/)
	{
		auto it = _findEdge(u, v);
		if (it != vertices.end()) {
			assert(false && "Duplication edge found in graph!");

			return false;
		}
		vertices.emplace_back(IntegerPair{u, v});
		weights.insert(std::pair<IntegerPair,float>(
			IntegerPair{ u, v },
			weight));

		return true;
	}

	bool Graph::removeEdge(int u, int v)
	{
		auto it = _findEdge(u, v);
		if (it != vertices.end()) {
			vertices.erase(it);
		}
		auto itw = weights.find(IntegerPair{ u, v });
		if (itw != weights.end()) {
			weights.erase(itw);

			return true;
		}

		return false;
	}

	Graph::VertexList Graph::getConnectedEdges(int u) const
	{
		VertexList result;
		result.reserve(vertices.size());

		for (const auto& pair : vertices) {
			if (u == pair.first) {
				result.emplace_back(u, pair.second);
			}
		}

		return result;
	}

	Graph::VertexList Graph::getVertexPairs() const
	{
		return vertices;
	}

	std::vector<int> Graph::getVertices() const {
		std::set<int> result;

		for (const auto pair : vertices) {
			result.insert(pair.first);
			result.insert(pair.second);
		}

		return std::vector<int>(result.begin(), result.end());
	}

	Graph::VertexList::const_iterator Graph::_findEdge(int u, int v) const
	{
		return std::find_if(vertices.begin(), vertices.end(), [u,v](const auto& pair) {
			return u == pair.first && v == pair.second;
		});
	}
} // Types namespace
