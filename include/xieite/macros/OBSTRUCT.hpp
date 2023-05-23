#ifndef XIEITE_HEADER_MACROS_OBSTRUCT
#	define XIEITE_HEADER_MACROS_OBSTRUCT

#	include <xieite/macros/DEFER.hpp>
#	include <xieite/macros/EMPTY.hpp>

#	define XIEITE_OBSTRUCT(...) \
		__VA_ARGS__ XIEITE_DEFER(XIEITE_EMPTY)()

#endif
