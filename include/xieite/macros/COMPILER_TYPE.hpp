#pragma once

#if defined(__GNUC__)
#	define XIEITE_COMPILER_TYPE_GCC
#endif

#if defined(__clang__)
#	define XIEITE_COMPILER_TYPE_CLANG
#endif

#if defined(__MINGW32__)
#	define XIEITE_COMPILER_TYPE_MINGW32
#endif

#if defined(__MINGW64__)
#	define XIEITE_COMPILER_TYPE_MINGW64
#endif

#if defined(_MSC_VER)
#	define XIEITE_COMPILER_TYPE_MSVC
#endif
