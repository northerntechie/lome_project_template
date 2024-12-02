/**
 * Lome sample project - Algorithms
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <variant>

namespace Types {

	using ValueType = std::variant<int,float,double>;

	class Node {
	public:
		explicit Node(ValueType value);

		const ValueType& get() const;
		void set(ValueType value);

	private:
		ValueType value;
	};
}
