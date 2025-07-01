/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 */
#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <tuple>

#define RED_BOLD(str) "\033[31;1m" str "\033[0m"
#define GREEN_BOLD(str) "\033[32;1m" str "\033[0m"

#define FUNCTION_NAME_TO_STRING(func) #func
#define TEST_HEADER(func) std::cout << func
#define TEST_PASSED_FOOTER() std::cout << "..." << GREEN_BOLD("Test passed.") << "\n"
#define TEST_FAILED_FOOTER() std::cout << "..." << RED_BOLD("Test failed!") << "\n"

namespace Test {
	template <typename Func>
	void TEST_METHOD_IMPL(Func&& func)
	{
		func();
	}

	inline static std::unordered_map<std::string,std::function<void()>> testFunctions = {};

	template<typename T>
	std::string stringifyVector(const std::vector<T>& vec) {
		std::stringstream ss;
		for (const auto& element : vec) {
			ss << element << " ";
		}
		return ss.str();
	}
}

#define TEST_ASSERT(expr, msg) \
	try { \
		if (!(expr)) { \
			throw std::runtime_error(msg); \
		} \
	} \
	catch(const std::exception& e) { \
		throw std::runtime_error(msg); \
	}

#define TEST_LAMBDA_BODY(functionName) \
	TEST_HEADER(#functionName); \
	try { \
		TEST_METHOD_IMPL(functionName); \
		TEST_PASSED_FOOTER(); \
	} \
	catch(const std::exception& e) { \
		std::cerr << "..." << e.what(); \
		TEST_FAILED_FOOTER(); \
	} \

#define REGISTER_TEST(functionName) \
	Test::testFunctions.emplace( \
		#functionName, \
		[]() { \
			TEST_LAMBDA_BODY(functionName) \
		})
