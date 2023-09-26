#ifndef XIEITE_HEADER__MACROS__REPEAT
#	define XIEITE_HEADER__MACROS__REPEAT

#	include "../macros/LOOP.hpp"

#	define XIEITE__REPEAT(iterations, argument) XIEITE__LOOP(iterations, XIEITE_INTERNAL__REPEAT, , argument)

#	define XIEITE_INTERNAL__REPEAT(accumulator, iteration, argument) accumulator argument

#endif
