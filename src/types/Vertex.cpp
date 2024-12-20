#include "Vertex.hpp"

bool Types::Vertex::operator==(const Vertex &other) const
{
	return id == other.id;
}