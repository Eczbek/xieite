#ifndef XIEITE_HEADER__MACROS__REPEAT_CONCATENATE
#	define XIEITE_HEADER__MACROS__REPEAT_CONCATENATE

#	include "../macros/CONCATENATE.hpp"
#	include "../macros/LOOP.hpp"

#	define XIEITE__REPEAT_CONCATENATE(count, argument) XIEITE__LOOP(count, XIEITE_INTERNAL__REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL__REPEAT_CONCATENATE(count, accumulator, argument) XIEITE__CONCATENATE(accumulator, argument)

#endif
