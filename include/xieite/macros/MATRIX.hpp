#pragma once
#include <vector> // std::vector
#include <xieite/macros/REPEAT.hpp>

// Thanks to eightfold for help

#define XIEITE_MATRIX(unsignedInteger, type) XIEITE_REPEAT(std::vector<, unsignedInteger) type XIEITE_REPEAT(>, unsignedInteger)
