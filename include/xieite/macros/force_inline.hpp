#ifndef XIEITE_HEADER__MACROS__FORCE_INLINE
#	define XIEITE_HEADER__MACROS__FORCE_INLINE

#	include "../macros/compiler_type.hpp"

#	if XIEITE__COMPILER_TYPE__GCC || XIEITE__COMPILER_TYPE__LLVM
#		define XIEITE__FORCE_INLINE [[gnu::always_inline]] inline
#	elif XIEITE__COMPILER_TYPE__CLANG
#		define XIEITE__FORCE_INLINE [[clang::always_inline]] inline
#	elif XIEITE__COMPILER_TYPE__MSVC
#		define XIEITE__FORCE_INLINE __forceinline
#	else
#		define XIEITE__FORCE_INLINE inline
#	endif

// Thanks to eightfold for original code

#endif
