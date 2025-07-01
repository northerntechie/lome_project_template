/**
 * Lome sample project - Math functions
 */
#pragma once

#include <vector>
#include <set>

namespace Math {
	unsigned int factorial(unsigned int input) noexcept;
	void heapGenerate(const std::set<char>& initialSet, std::vector<std::set<char>> result);
}