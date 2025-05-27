#ifndef DETAIL_XIEITE_HEADER_PP_HAS_DECLSPEC
#	define DETAIL_XIEITE_HEADER_PP_HAS_DECLSPEC
#
#	include "../pp/compiler.hpp"
#
#	if XIEITE_COMPILER_TYPE_CLANG
#		ifdef __has_declspec_attribute
#			define XIEITE_HAS_DECLSPEC(...) __has_declspec_attribute(__VA_ARGS__)
#		else
#			define XIEITE_HAS_DECLSPEC(...) 0
#		endif
#	else
#		define XIEITE_HAS_DECLSPEC(...) XIEITE_COMPILER_TYPE_MSVC
#	endif
#endif

// Thanks to Ian Pike (https://github.com/Rinzii) for original code
