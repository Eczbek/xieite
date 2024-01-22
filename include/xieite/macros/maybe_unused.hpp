#ifndef XIEITE_HEADER_MACROS_MAYBE_UNUSED
#	define XIEITE_HEADER_MACROS_MAYBE_UNUSED

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_MAYBE_UNUSED [[maybe_unused]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_MAYBE_UNUSED __attribute__((unused))
#	else
#		define XIEITE_MAYBE_UNUSED
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
