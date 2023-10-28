#ifndef XIEITE_HEADER_MACROS_REPEAT_CONCATENATE
#	define XIEITE_HEADER_MACROS_REPEAT_CONCATENATE

#	include "../macros/concatenate.hpp"
#	include "../macros/loop.hpp"

#	define XIEITE_REPEAT_CONCATENATE(iterations, argument) XIEITE_LOOP(iterations, XIEITE_INTERNAL_REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL_REPEAT_CONCATENATE(accumulator, argument, iteration) XIEITE_CONCATENATE(accumulator, argument)

#endif
