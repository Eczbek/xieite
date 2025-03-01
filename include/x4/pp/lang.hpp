#pragma once

#define X4LANG_C 0
#define X4LANGMAJOR_C 0
#define X4LANGMINOR_C 0
#define X4LANGPATCH_C 0
#define X4LANG_CPP 0
#define X4LANGMAJOR_CPP 0
#define X4LANGMINOR_CPP 0
#define X4LANGPATCH_CPP 0
#define X4LANG_CPP_CLI 0
#define X4LANGMAJOR_CPP_CLI 0
#define X4LANGMINOR_CPP_CLI 0
#define X4LANGPATCH_CPP_CLI 0
#define X4LANG_CPP_CX 0
#define X4LANGMAJOR_CPP_CX 0
#define X4LANGMINOR_CPP_CX 0
#define X4LANGPATCH_CPP_CX 0
#define X4LANG_CPP_EMBEDDED 0
#define X4LANGMAJOR_CPP_EMBEDDED 0
#define X4LANGMINOR_CPP_EMBEDDED 0
#define X4LANGPATCH_CPP_EMBEDDED 0
#define X4LANG_CPP_WINRT 0
#define X4LANGMAJOR_CPP_WINRT 0
#define X4LANGMINOR_CPP_WINRT 0
#define X4LANGPATCH_CPP_WINRT 0
#define X4LANG_CUDA 0
#define X4LANGMAJOR_CUDA 0
#define X4LANGMINOR_CUDA 0
#define X4LANGPATCH_CUDA 0
#define X4LANG_GLSL 0
#define X4LANGMAJOR_GLSL 0
#define X4LANGMINOR_GLSL 0
#define X4LANGPATCH_GLSL 0
#define X4LANG_HLSL 0
#define X4LANGMAJOR_HLSL 0
#define X4LANGMINOR_HLSL 0
#define X4LANGPATCH_HLSL 0
#define X4LANG_METAL 0
#define X4LANGMAJOR_METAL 0
#define X4LANGMINOR_METAL 0
#define X4LANGPATCH_METAL 0
#define X4LANG_OBJECTIVE_C 0
#define X4LANGMAJOR_OBJECTIVE_C 0
#define X4LANGMINOR_OBJECTIVE_C 0
#define X4LANGPATCH_OBJECTIVE_C 0
#define X4LANG_PSSL 0
#define X4LANGMAJOR_PSSL 0
#define X4LANGMINOR_PSSL 0
#define X4LANGPATCH_PSSL 0

#define X4LANGEQ(type, major, ...) DETAIL_X4LANG(__VA_ARGS__, DETAIL_X4LANGEQ(type, major, __VA_ARGS__), DETAIL_X4LANGEQ(type, major, __VA_ARGS__, 0), DETAIL_X4LANGEQ(type, major, 0, 0))
#define X4LANGLEAST(type, major, ...) DETAIL_X4LANG(__VA_ARGS__, DETAIL_X4LANGLEAST(type, major, __VA_ARGS__), DETAIL_X4LANGLEAST(type, major, __VA_ARGS__, 0), DETAIL_X4LANGLEAST(type, major, 0, 0))
#define X4LANGMOST(type, major, ...) DETAIL_X4LANG(__VA_ARGS__, DETAIL_X4LANGMOST(type, major, __VA_ARGS__), DETAIL_X4LANGMOST(type, major, __VA_ARGS__, 0), DETAIL_X4LANGMOST(type, major, 0, 0))
#define DETAIL_X4LANG(_0, _1, _2, x, ...) x
#define DETAIL_X4LANGEQ(type, major, minor, patch) (X4LANG_##type && (X4LANGMAJOR_##type == (major)) && (X4LANGMINOR_##type == (minor)) && (X4LANGPATCH_##type == (patch)))
#define DETAIL_X4LANGLEAST(type, major, minor, patch) (X4LANG_##type && ((X4LANGMAJOR_##type > (major)) || (X4LANGMAJOR_##type == (major)) && ((X4LANGMINOR_##type > (minor)) || (X4LANGMINOR_##type == (minor)) && (X4LANGPATCH_##type >= (patch)))))
#define DETAIL_X4LANGMOST(type, major, minor, patch) (X4LANG_##type && ((X4LANGMAJOR_##type < (major)) || (X4LANGMAJOR_##type == (major)) && ((X4LANGMINOR_##type < (minor)) || (X4LANGMINOR_##type == (minor)) && (X4LANGPATCH_##type <= (patch)))))

#if defined(__STDC__) || defined(__STDC_VERSION__)
#	undef X4LANG_C
#	define X4LANG_C 1

#	undef X4LANGMAJOR_C
#	ifdef __STDC_VERSION__
#		define X4LANGMAJOR_C (__STDC_VERSION__ / 100)
#	else
#		define X4LANGMAJOR_C 1989
#	endif
#endif

#ifdef __cplusplus
#	undef X4LANG_CPP
#	define X4LANG_CPP 1

#	undef X4LANGMAJOR_CPP
#	ifdef _MSVC_LANG
#		define X4LANGMAJOR_CPP (_MSVC_LANG / 100)
#	else
#		define X4LANGMAJOR_CPP (__cplusplus / 100)
#	endif
#endif

#ifdef __cplusplus_cli
#	undef X4LANG_CPP_CLI
#	define X4LANG_CPP_CLI 1
#endif

#ifdef __cplusplus_winrt
#	undef X4LANG_CPP_CX
#	define X4LANG_CPP_CX 1
#endif

#ifdef __embedded_cplusplus
#	undef X4LANG_CPP_EMBEDDED
#	define X4LANG_CPP_EMBEDDED 1
#endif

#ifdef CPPWINRT_VERSION
#	undef X4LANG_CPP_WINRT
#	define X4LANG_CPP_WINRT 1
#endif

#if defined(__CUDA__) || defined(__CUDACC__)
#	include <cuda.h>

#	undef X4LANG_CUDA
#	define X4LANG_CUDA 1

#	ifdef CUDA_VERSION
#		undef X4LANGMAJOR_CUDA
#		define X4LANGMAJOR_CUDA (CUDA_VERSION / 1000)

#		undef X4LANGMINOR_CUDA
#		define X4LANGMINOR_CUDA (CUDA_VERSION % 1000 / 10)

#		undef X4LANGPATCH_CUDA
#		define X4LANGPATCH_CUDA (CUDA_VERSION % 10)
#	endif
#endif

#ifdef __GLSL__
#	undef X4LANG_GLSL
#	define X4LANG_GLSL 1

#	ifdef GLSL_VERSION
#		undef X4LANGMAJOR_GLSL
#		define X4LANGMAJOR_GLSL (GLSL_VERSION / 100)

#		undef X4LANGMINOR_GLSL
#		define X4LANGMINOR_GLSL (GLSL_VERSION % 100 / 10)
#	endif
#endif

#ifdef __HLSL__
#	undef X4LANG_HLSL
#	define X4LANG_HLSL 1

#	ifdef __HLSL_VERSION
#		undef X4LANGMAJOR_HLSL
#		define X4LANGMAJOR_HLSL __HLSL_VERSION
#	endif
#endif

#ifdef __METAL__
#	undef X4LANG_METAL
#	define X4LANG_METAL 1
#endif

#ifdef __OBJC__
#	undef X4LANG_OBJECTIVE_C
#	define X4LANG_OBJECTIVE_C 1
#endif

#ifdef __PSSL__
#	undef X4LANG_PSSL
#	define X4LANG_PSSL 1
#endif
