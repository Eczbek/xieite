#pragma once
#include <stdexcept> // std::runtime_error

// Thanks to Raldryniorth, m1lkweed, and eightfold for help

#define XIEITE_ASSERT(booleanExpression, stringLiteral) \
	static_assert((__builtin_constant_p((booleanExpression)) ? (booleanExpression) : true), stringLiteral); \
	if !consteval { \
		if (!(booleanExpression)) \
			throw std::runtime_error(stringLiteral); \
	}
