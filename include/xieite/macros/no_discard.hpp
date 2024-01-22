#ifndef XIEITE_HEADER_MACROS_NO_DISCARD
#	define XIEITE_HEADER_MACROS_NO_DISCARD

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_LANGUAGE_STANDARD_CPP_2017
#		define XIEITE_NO_DISCARD [[nodiscard]]
#	elif XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIETIE_NO_DISCARD __attribute__((warn_unused_result))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_NO_DISCARD __checkReturn
#	else
#		define XIEITE_NO_DISCARD
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
