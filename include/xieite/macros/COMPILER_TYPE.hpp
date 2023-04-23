#pragma once

#if defined(__GNUC__)
#	define XIEITE_COMPILER_TYPE_GCC
#elif defined(__clang__)
#	define XIEITE_COMPILER_TYPE_CLANG
#elif defined(__MINGW32__) || defined(__MINGW64__)
#	define XIEITE_COMPILER_TYPE_MINGW
#elif defined(_MSC_VER)
#	define XIEITE_COMPILER_TYPE_MSVC
#endif
