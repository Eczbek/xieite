#ifndef XIEITE_HEADER_MACROS_REPEAT_CONCATENATE
#	define XIEITE_HEADER_MACROS_REPEAT_CONCATENATE

#	include <xieite/macros/CONCATENATE.hpp>
#	include <xieite/macros/LOOP.hpp>

#	define XIEITE_REPEAT_CONCATENATE(count, argument) XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT_CONCATENATE, , argument)

#	define XIEITE_INTERNAL_REPEAT_CONCATENATE(count, accumulator, argument) XIEITE_CONCATENATE(accumulator, argument)

#endif
