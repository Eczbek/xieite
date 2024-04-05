#ifndef XIEITE_HEADER_MACROS_LIFT
#	define XIEITE_HEADER_MACROS_LIFT

#	include "../macros/forward.hpp"

#	define XIEITE_LIFT(function_) \
		([](auto&&... arguments_) noexcept(noexcept(function_(XIEITE_FORWARD(arguments_)...))) -> decltype(function_(XIEITE_FORWARD(arguments_)...)) { \
			return function_(XIEITE_FORWARD(arguments_)...); \
		})

#endif
