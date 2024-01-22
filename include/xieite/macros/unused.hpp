#ifndef XIEITE_HEADER_MACROS_UNUSED
#	define XIEITE_HEADER_MACROS_UNUSED

#	include "../language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_1998
#		define XIEITE_UNUSED(...) static_cast<void>(0 __VA_OPT__(,) __VA_ARGS__)
#	else
#		define XIEITE_UNUSED(...) (void)(0 __VA_OPT__(,) __VA_ARGS__)
#	endif

#endif
