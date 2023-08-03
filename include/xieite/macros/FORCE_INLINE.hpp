#ifndef XIEITE_HEADER_MACROS_FORCE_INLINE
#	define XIEITE_HEADER_MACROS_FORCE_INLINE

#	include "../macros/COMPILER_TYPE.hpp"

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_LLVM
#		define XIEITE_FORCE_INLINE [[gnu::always_inline]] inline
#	elif XIEITE_COMPILER_TYPE_CLANG
#		define XIEITE_FORCE_INLINE [[clang::always_inline]] inline
#	elif XIEITE_COMPILER_TYPE_MSVC
#		define XIEITE_FORCE_INLINE __forceinline
#	else
#		define XIEITE_FORCE_INLINE inline
#	endif

// Thanks to eightfold for original code

#endif
