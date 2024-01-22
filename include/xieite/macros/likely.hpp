#ifndef XIEITE_HEADER_MACROS_LIKELY
#	define XIEITE_HEADER_MACROS_LIKELY

#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2020
#		define XIEITE_LIKELY [[likely]]
#	else
#		define XIEITE_LIKELY
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
