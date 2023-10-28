#ifndef XIEITE_HEADER_MACROS_REPEAT
#	define XIEITE_HEADER_MACROS_REPEAT

#	include "../macros/loop.hpp"

#	define XIEITE_REPEAT(iterations, argument) XIEITE_LOOP(iterations, XIEITE_INTERNAL_REPEAT, , argument)

#	define XIEITE_INTERNAL_REPEAT(accumulator, iteration, argument) accumulator argument

#endif
