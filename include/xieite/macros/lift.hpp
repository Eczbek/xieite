#ifndef XIEITE_HEADER_MACROS_LIFT
#	define XIEITE_HEADER_MACROS_LIFT

#	include "../macros/forward.hpp"

#	define XIEITE_LIFT(...) \
		([](auto&&... arguments) noexcept(noexcept(__VA_ARGS__(XIEITE_FORWARD(arguments)...))) -> decltype(__VA_ARGS__(XIEITE_FORWARD(arguments)...)) { \
			return __VA_ARGS__(XIEITE_FORWARD(arguments)...); \
		})

#endif
