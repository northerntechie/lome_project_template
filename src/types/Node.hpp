/**
 * Lome sample project - Algorithms
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <variant>
#include <string>
#include <optional>

namespace Types {

	using ValueType = std::variant<int,float,double,std::string>;

	class Node {
	public:
		explicit Node(ValueType value);

		template<typename T>
		std::optional<T> get() const;
		void set(ValueType value);

	private:
		ValueType value;
	};
}
