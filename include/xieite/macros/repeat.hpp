#ifndef XIEITE_HEADER_MACROS_REPEAT
#	define XIEITE_HEADER_MACROS_REPEAT

#	include "../macros/loop.hpp"

#	define XIEITE_REPEAT(iterations, argument) XIEITE_LOOP(iterations, XIEITE_REPEAT_INTERNAL, , argument)

#	define XIEITE_REPEAT_INTERNAL(accumulator, iteration, argument) accumulator argument

#endif
