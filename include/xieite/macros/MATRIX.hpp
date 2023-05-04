#pragma once

#include <vector>
#include <xieite/macros/REPEAT.hpp>

#define XIEITE_MATRIX(type, dimensions) \
	XIEITE_REPEAT(dimensions, std::vector<) type XIEITE_REPEAT(dimensions, >)

// Thanks to eightfold for help
