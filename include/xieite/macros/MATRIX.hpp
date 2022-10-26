#pragma once
#include <xieite/macros/REPEAT.hpp>
#include <vector>

#define GCUFL_MATRIX(d, t) GCUFL_REPEAT(std::vector<, d) t GCUFL_REPEAT(>, d)
