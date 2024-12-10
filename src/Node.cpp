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

	template<typename T>
	std::optional<T> Node::get() const {
		return std::visit([](const auto& _value) -> std::optional<T> {
			if constexpr (std::is_same_v<T, decltype(_value)>) {
				return _value;
			} else {
				return std::nullopt;
			}
		}, value);
	}

	void Node::set(ValueType value) {
		this->value = value;
	}

	// Explicit instantiation for int
	template std::optional<int> Node::get<int>() const;
	template std::optional<std::string> Node::get<std::string>() const;
}
