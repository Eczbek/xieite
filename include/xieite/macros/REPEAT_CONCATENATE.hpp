#ifndef XIEITE_HEADER__MACROS__REPEAT_CONCATENATE
#	define XIEITE_HEADER__MACROS__REPEAT_CONCATENATE

#	include "../macros/CONCATENATE.hpp"
#	include "../macros/LOOP.hpp"

#	define XIEITE__REPEAT_CONCATENATE(iterations, argument) XIEITE__LOOP(iterations, XIEITE_INTERNAL__REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL__REPEAT_CONCATENATE(accumulator, argument, iteration) XIEITE__CONCATENATE(accumulator, argument)

#endif
