#ifndef XIEITE_HEADER__MACROS__REPEAT_CONCATENATE
#	define XIEITE_HEADER__MACROS__REPEAT_CONCATENATE

#	include "../macros/concatenate.hpp"
#	include "../macros/loop.hpp"

#	define XIEITE__REPEAT_CONCATENATE(iterations, argument) XIEITE__LOOP(iterations, XIEITE_INTERNAL__REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL__REPEAT_CONCATENATE(accumulator, argument, iteration) XIEITE__CONCATENATE(accumulator, argument)

#endif
