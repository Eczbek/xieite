#pragma once

#if defined(__GNUC__)
#	define XIEITE_COMPILER_GCC
#endif

#if defined(__clang__)
#	define XIEITE_COMPILER_CLANG
#endif

#if defined(__MINGW32__) || defined(__MINGW64__)
#	define XIEITE_COMPILER_MINGW
#endif

#if defined(_MSC_VER)
#	define XIEITE_COMPILER_VISUAL_STUDIO
#endif

#if defined(__EMSCRIPTEN__)
#	define XIEITE_COMPILER_EMSCRIPTEN
#endif
