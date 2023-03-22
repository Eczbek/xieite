#pragma once

#include <vector>
#include <xieite/macros/REPEAT.hpp>

#define XIEITE_MATRIX(unsignedInteger, type) XIEITE_REPEAT(std::vector<, unsignedInteger) type XIEITE_REPEAT(>, unsignedInteger)

// Thanks to eightfold for help
