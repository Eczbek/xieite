#ifndef XIEITE_HEADER__MACROS__MATRIX
#	define XIEITE_HEADER__MACROS__MATRIX

#	include <vector>
#	include "../macros/REPEAT.hpp"

#	define XIEITE__MATRIX(dimensions, type) XIEITE__REPEAT(dimensions, std::vector<) type XIEITE__REPEAT(dimensions, >)

// Thanks to eightfold for help

#endif
