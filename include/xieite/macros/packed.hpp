#ifndef XIEITE_HEADER_MACROS_PACKED
#	define XIEITE_HEADER_MACROS_PACKED

#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_PACKED(...) [[gnu::packed]] __VA_ARGS__
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_PACKED(...) __pragma(pack(push, 1)) __VA_ARGS__ __pragma(pack(pop))
#	else
#		define XIEITE_PACKED(...) __VA_ARGS__
#	endif

#endif
