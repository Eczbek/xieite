#pragma once

#include "../macros/compiler.hpp"

#if XIEITE_COMPILER_GCC || XIEITE_COMPILER_LLVM
#	define XIEITE_FORCE_INLINE [[gnu::always_inline]] inline
#elif XIEITE_COMPILER_CLANG
#	define XIEITE_FORCE_INLINE [[clang::always_inline]] inline
#elif XIEITE_COMPILER_MSVC
#	define XIEITE_FORCE_INLINE __forceinline
#else
#	define XIEITE_FORCE_INLINE inline
#endif

// Thanks to eightfold for original code
