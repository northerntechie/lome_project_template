/**
 * Lome sample project - Algorithms
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#include "Node.hpp"

namespace Types {
	Node::Node(ValueType value) : value(value) {}

	const ValueType& Node::get() const {
		return value;
	}

	void Node::set(ValueType value) {
		this->value = value;
	}
}
