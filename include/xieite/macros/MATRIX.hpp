#pragma once
#include <vector>
#include <xieite/macros/REPEAT.hpp>

#define GCUFL_MATRIX(d, t) GCUFL_REPEAT(std::vector<, d) t GCUFL_REPEAT(>, d)
