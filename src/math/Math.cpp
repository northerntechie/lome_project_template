/**
 * Lome sample project - Math functions
 */

#include "Math.hpp"

namespace Math {

	unsigned int factorial(unsigned int input) noexcept
	{
		int result = 1;

		while (input > 0) {
			result *= input;
			--input;
		}

		return result;
	}

	void heapGenerate(const std::set<char>& /*initialSet*/, std::vector<std::set<char>> /*result*/) {}

} // namespace Math