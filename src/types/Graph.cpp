#include "Graph.hpp"
#include <nlohmann/json.hpp>

#include <algorithm>
#include <cassert>

namespace Types {
	Graph::Graph(int maxVertices, bool directed /*= false*/)
	: maxVertices(maxVertices), directed(directed) {
		edges.reserve(maxVertices);
	}

	void Graph::load(std::string_view file)
	{
		// TODO(Todd): Implementation needed
	}

	bool Graph::isDirected() const
	{
		return directed;
	}

	int Graph::numVertices() const
	{
		return 0;
	}

	bool Graph::isEdge(int u, int v) const
	{
		return false;
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
		auto edge = std::find_if(edges.begin(), edges.end(), [u,v](const auto& _edge) {
			return u == _edge.startId && v == _edge.endId;
		});
		if (edge != edges.end()) {
			assert(false && "Duplication edge found in graph!");

			return false;
		}
		edges.emplace_back(u,v,weight);

		return true;
	}

	bool Graph::removeEdge(int u, int v)
	{

		return false;
	}
} // Types namespace
