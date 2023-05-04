#pragma once

#include <xieite/macros/CONCATENATE.hpp>
#include <xieite/macros/LOOP.hpp>

#define XIEITE_REPEAT_CONCATENATE(count, expression) \
	XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT_CONCATENATE, , expression)

#define XIEITE_INTERNAL_REPEAT_CONCATENATE(count, accumulator, expression) \
	XIEITE_CONCATENATE(accumulator, expression)
