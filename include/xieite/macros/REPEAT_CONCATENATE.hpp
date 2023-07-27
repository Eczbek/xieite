#ifndef XIEITE_HEADER_MACROS_REPEAT_CONCATENATE
#	define XIEITE_HEADER_MACROS_REPEAT_CONCATENATE

#	include "../macros/CONCATENATE.hpp"
#	include "../macros/LOOP.hpp"

#	define XIEITE_REPEAT_CONCATENATE(count, argument) XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL_REPEAT_CONCATENATE(count, accumulator, argument) XIEITE_CONCATENATE(accumulator, argument)

#endif
