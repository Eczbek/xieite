#ifndef XIEITE_HEADER_MACROS_OBSTRUCT
#	define XIEITE_HEADER_MACROS_OBSTRUCT

#	include "../macros/defer.hpp"
#	include "../macros/empty.hpp"

#	define XIEITE_OBSTRUCT(...) __VA_ARGS__ XIEITE_DEFER(XIEITE_EMPTY)()

#endif
