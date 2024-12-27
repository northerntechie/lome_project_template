/**
 * Lome sample project - AlgorithmLibrary
 * 
 * Derived from "Algorithms in a Nutshell", Heineman, G.T., Pollice G., Selkow S.
 * O'Reilly, 2009
 * 
 * (C) Copyright 2024-, Todd Saharchuk
 */
#pragma once

#include <iostream>
#include <stdexcept>

#define FUNCTION_NAME_TO_STRING(func) #func
#define TEST_HEADER(func) std::cout << func
#define TEST_PASSED_FOOTER() std::cout << "...Test passed.\n"
#define TEST_FAILED_FOOTER() std::cout << "...Test failed!\n"

namespace Test {
	template <typename Func>
	void TEST_METHOD_IMPL(Func&& func)
	{
		func();
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

#define TEST_METHOD(functionName) \
	void functionName ## _TestImpl() { \
		TEST_HEADER(#functionName); \
		try { \
			TEST_METHOD_IMPL(functionName); \
			TEST_PASSED_FOOTER(); \
		} \
		catch(const std::exception& e) { \
			std::cerr << " " << e.what() << " "; \
			TEST_FAILED_FOOTER(); \
		} \
	}
