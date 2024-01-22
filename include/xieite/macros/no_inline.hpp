#ifndef XIEITE_HEADER_MACROS_NO_INLINE
#	define XIEITE_HEADER_MACROS_NO_INLINE

#	include "../macros/compiler_type.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_NO_INLINE __attribute__((noinline))
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_NO_INLINE __declspec(noinline)
#	else
#		define XIEITE_NO_INLINE
#	endif

#endif

// Thanks to Ian Pike for original code
// https://github.com/Rinzii
