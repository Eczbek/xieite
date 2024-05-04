#ifndef XIEITE_HEADER_MACROS_LIFT
#	define XIEITE_HEADER_MACROS_LIFT

#	include "../macros/forward.hpp"

#	define XIEITE_LIFT(function_) \
		([](auto&&... arguments) noexcept(noexcept(function_(XIEITE_FORWARD(arguments)...))) -> decltype(function_(XIEITE_FORWARD(arguments)...)) { \
			return function_(XIEITE_FORWARD(arguments)...); \
		})

#endif
