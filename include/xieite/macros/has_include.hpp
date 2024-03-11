#ifndef XIEITE_HEADER_MACROS_HAS_INCLUDE
#	define XIEITE_HEADER_MACROS_HAS_INCLUDE

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017 || XIEITE_LANGUAGE_STANDARD_C_2023 || defined(__has_include)
#		define XIEITE_HAS_INCLUDE(...) __has_include(__VA_ARGS__)
#	else
#		define XEIITE_HAS_INCLUDE(...) 0
#	endif
#endif
