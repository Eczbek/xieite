#ifndef XIEITE_HEADER_MACROS_LIFT
#	define XIEITE_HEADER_MACROS_LIFT

#	include "../macros/forward.hpp"

#	define XIEITE_LIFT(...) \
		([][[nodiscard]](auto&&... arguments) noexcept(noexcept(__VA_ARGS__(XIEITE_FORWARD(arguments)...))) -> decltype(__VA_ARGS__(XIEITE_FORWARD(arguments)...)) { \
			return __VA_ARGS__(XIEITE_FORWARD(arguments)...); \
		})

#	define XIEITE_LIFT_UNARY(...) \
		([][[nodiscard]](auto&& argument) noexcept(noexcept(__VA_ARGS__(XIEITE_FORWARD(argument)))) -> decltype(__VA_ARGS__(XIEITE_FORWARD(argument))) { \
			return __VA_ARGS__(XIEITE_FORWARD(argument)); \
		})

#endif
