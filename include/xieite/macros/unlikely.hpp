#ifndef XIEITE_HEADER_MACROS_UNLIKELY
#	define XIEITE_HEADER_MACROS_UNLIKELY

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		define XIEITE_UNLIKELY [[unlikely]]
#	else
#		define XIEITE_UNLIKELY
#	endif

#endif
