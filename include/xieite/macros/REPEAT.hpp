#pragma once

#include <xieite/macros/LOOP.hpp>

#define XIEITE_REPEAT(count, expression) \
	XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT, , expression)

#define XIEITE_INTERNAL_REPEAT(count, accumulator, expression) \
	accumulator expression
