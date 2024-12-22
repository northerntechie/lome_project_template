#include "Graph.hpp"

#include <nlohmann/json.hpp>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>

namespace Types {

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
			edges.emplace_back(it["startId"].get<int>(), it["endId"].get<int>(), it["weight"].get<float>());
			++numEdges;
		}
		std::cout << "Processed " << numEdges << " edges...\n";

		return true;
	}

	bool Graph::isDirected() const
	{
		return directed;
	}

	int Graph::numVertices() const
	{
		return edges.size();
	}

	bool Graph::isEdge(int u, int v) const
	{
		auto it = std::find_if(edges.begin(), edges.end(), [u,v](const auto& edge) {
			return edge.startId == u && edge.endId == v;
		});
		return it != edges.end();
	}

	float Graph::edgeWeight(int u, int v) const
	{
		auto edge = std::find_if(edges.begin(), edges.end(), [u,v](const auto& _edge) -> bool {
			return _edge.startId == u && _edge.endId == v;
		});
		if (edge != edges.end()) {
			return edge->weight;
		}
	
		assert(false && "Edge does not exist");
		return 0.0f;
	}

	bool Graph::addEdge(int u, int v, float weight)
	{
		auto it = std::find_if(edges.begin(), edges.end(), [u,v](const auto& _edge) {
			return u == _edge.startId && v == _edge.endId;
		});
		if (it != edges.end()) {
			assert(false && "Duplication edge found in graph!");

			return false;
		}
		edges.emplace_back(u,v,weight);

		return true;
	}

	bool Graph::removeEdge(int u, int v)
	{
		auto it = std::find_if(edges.begin(), edges.end(), [u,v](const auto& _edge) {
			return u == _edge.startId && v == _edge.endId;
		});

		if (it != edges.end()) {
			edges.erase(it);

			return true;
		}

		return false;
	}
} // Types namespace
