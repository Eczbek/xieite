#ifndef XIEITE_HEADER_MACROS_MATRIX
#	define XIEITE_HEADER_MACROS_MATRIX

#	include <vector>
#	include <xieite/macros/REPEAT.hpp>

#	define XIEITE_MATRIX(type, dimensions) \
		XIEITE_REPEAT(dimensions, std::vector<) type XIEITE_REPEAT(dimensions, >)

// Thanks to eightfold for help

#endif
