#ifndef XIEITE_HEADER_MACROS_LIFT
#	define XIEITE_HEADER_MACROS_LIFT

#	include "../macros/forward.hpp"

#	define XIEITE_LIFT(function) \
		[](auto&&... arguments) noexcept(noexcept(function(XIEITE_FORWARD(arguments)...))) -> decltype(function(XIEITE_FORWARD(arguments)...)) { \
			return function(XIEITE_FORWARD(arguments)...); \
		}

#endif
