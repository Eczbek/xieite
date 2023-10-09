#ifndef XIEITE_HEADER__MACROS__OBSTRUCT
#	define XIEITE_HEADER__MACROS__OBSTRUCT

#	include "../macros/defer.hpp"
#	include "../macros/empty.hpp"

#	define XIEITE__OBSTRUCT(...) __VA_ARGS__ XIEITE__DEFER(XIEITE__EMPTY)()

#endif
