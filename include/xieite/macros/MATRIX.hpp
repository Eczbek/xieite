#pragma once
#include <vector> // std::vector
#include <xieite/macros/REPEAT.hpp>

#define XIEITE_MATRIX(d, t) XIEITE_REPEAT(std::vector<, d) t XIEITE_REPEAT(>, d)
