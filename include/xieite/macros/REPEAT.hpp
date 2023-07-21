#ifndef XIEITE_HEADER_MACROS_REPEAT
#	define XIEITE_HEADER_MACROS_REPEAT

#	include <xieite/macros/LOOP.hpp>

#	define XIEITE_REPEAT(count, argument) XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT, , argument)

#	define XIEITE_INTERNAL_REPEAT(count, accumulator, argument) accumulator argument

#endif
