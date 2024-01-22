#ifndef XIEITE_HEADER_MACROS_FORCE_INLINE
#	define XIEITE_HEADER_MACROS_FORCE_INLINE

#	include "../macros/compiler_type.hpp"
#	include "../macros/language_standard.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_FORCE_INLINE __attribute__((always_inline)) inline
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_FORCE_INLINE __forceinline
#	else
#		define XIEITE_FORCE_INLINE inline
#	endif

#endif

// Thanks to eightfold for original code
// https://github.com/8ightfold
