#ifndef XIEITE_HEADER_MACROS_FORCE_INLINE
#	define XIEITE_HEADER_MACROS_FORCE_INLINE

#	include "../macros/COMPILER_TYPE.hpp"

#	define XIEITE_FORCE_INLINE inline

#	if XIEITE_COMPILER_TYPE_GCC || XIEITE_COMPILER_TYPE_LLVM
#		undef XIEITE_FORCE_INLINE
#		define XIEITE_FORCE_INLINE [[gnu::always_inline]] inline
#	endif

#	if XIEITE_COMPILER_TYPE_CLANG
#		undef XIEITE_FORCE_INLINE
#		define XIEITE_FORCE_INLINE [[clang::always_inline]] inline
#	endif

#	if XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_FORCE_INLINE
#		define XIEITE_FORCE_INLINE __forceinline
#	endif

// Thanks to eightfold for original code

#endif
