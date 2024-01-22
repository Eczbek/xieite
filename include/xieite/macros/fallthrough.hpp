#ifndef XIEITE_HEADER_MACROS_FALLTHROUGH
#	define XIEITE_HEADER_MACROS_FALLTHROUGH

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_FALLTHROUGH [[fallthrough]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_FALLTHROUGH __attribute__((fallthrough))
#	elif XIEITE_XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_FALLTHROUGH __fallthrough
#	else
#		define XIEITE_FALLTHROUGH
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
