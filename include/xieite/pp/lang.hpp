#ifndef DETAIL_XIEITE_HEADER_PP_LANG
#	define DETAIL_XIEITE_HEADER_PP_LANG
#
#	define XIEITE_LANG_TYPE_C 0
#	define XIEITE_LANG_MAJOR_C 0
#	define XIEITE_LANG_MINOR_C 0
#	define XIEITE_LANG_PATCH_C 0
#	define XIEITE_LANG_TYPE_CPP 0
#	define XIEITE_LANG_MAJOR_CPP 0
#	define XIEITE_LANG_MINOR_CPP 0
#	define XIEITE_LANG_PATCH_CPP 0
#	define XIEITE_LANG_TYPE_CPP_CLI 0
#	define XIEITE_LANG_MAJOR_CPP_CLI 0
#	define XIEITE_LANG_MINOR_CPP_CLI 0
#	define XIEITE_LANG_PATCH_CPP_CLI 0
#	define XIEITE_LANG_TYPE_CPP_CX 0
#	define XIEITE_LANG_MAJOR_CPP_CX 0
#	define XIEITE_LANG_MINOR_CPP_CX 0
#	define XIEITE_LANG_PATCH_CPP_CX 0
#	define XIEITE_LANG_TYPE_CPP_EMBEDDED 0
#	define XIEITE_LANG_MAJOR_CPP_EMBEDDED 0
#	define XIEITE_LANG_MINOR_CPP_EMBEDDED 0
#	define XIEITE_LANG_PATCH_CPP_EMBEDDED 0
#	define XIEITE_LANG_TYPE_CPP_WINRT 0
#	define XIEITE_LANG_MAJOR_CPP_WINRT 0
#	define XIEITE_LANG_MINOR_CPP_WINRT 0
#	define XIEITE_LANG_PATCH_CPP_WINRT 0
#	define XIEITE_LANG_TYPE_CUDA 0
#	define XIEITE_LANG_MAJOR_CUDA 0
#	define XIEITE_LANG_MINOR_CUDA 0
#	define XIEITE_LANG_PATCH_CUDA 0
#	define XIEITE_LANG_TYPE_GLSL 0
#	define XIEITE_LANG_MAJOR_GLSL 0
#	define XIEITE_LANG_MINOR_GLSL 0
#	define XIEITE_LANG_PATCH_GLSL 0
#	define XIEITE_LANG_TYPE_HLSL 0
#	define XIEITE_LANG_MAJOR_HLSL 0
#	define XIEITE_LANG_MINOR_HLSL 0
#	define XIEITE_LANG_PATCH_HLSL 0
#	define XIEITE_LANG_TYPE_METAL 0
#	define XIEITE_LANG_MAJOR_METAL 0
#	define XIEITE_LANG_MINOR_METAL 0
#	define XIEITE_LANG_PATCH_METAL 0
#	define XIEITE_LANG_TYPE_OBJECTIVE_C 0
#	define XIEITE_LANG_MAJOR_OBJECTIVE_C 0
#	define XIEITE_LANG_MINOR_OBJECTIVE_C 0
#	define XIEITE_LANG_PATCH_OBJECTIVE_C 0
#	define XIEITE_LANG_TYPE_PSSL 0
#	define XIEITE_LANG_MAJOR_PSSL 0
#	define XIEITE_LANG_MINOR_PSSL 0
#	define XIEITE_LANG_PATCH_PSSL 0
#
#	define XIEITE_LANG_EQ(type, major, ...) DETAIL_XIEITE_LANG(__VA_ARGS__, DETAIL_XIEITE_LANG_EQ(type, major, __VA_ARGS__), DETAIL_XIEITE_LANG_EQ(type, major, __VA_ARGS__, 0), DETAIL_XIEITE_LANG_EQ(type, major, 0, 0))
#	define XIEITE_LANG_LEAST(type, major, ...) DETAIL_XIEITE_LANG(__VA_ARGS__, DETAIL_XIEITE_LANG_LEAST(type, major, __VA_ARGS__), DETAIL_XIEITE_LANG_LEAST(type, major, __VA_ARGS__, 0), DETAIL_XIEITE_LANG_LEAST(type, major, 0, 0))
#	define XIEITE_LANG_MOST(type, major, ...) DETAIL_XIEITE_LANG(__VA_ARGS__, DETAIL_XIEITE_LANG_MOST(type, major, __VA_ARGS__), DETAIL_XIEITE_LANG_MOST(type, major, __VA_ARGS__, 0), DETAIL_XIEITE_LANG_MOST(type, major, 0, 0))
#	define DETAIL_XIEITE_LANG(_0, _1, _2, x, ...) x
#	define DETAIL_XIEITE_LANG_EQ(type, major, minor, patch) (XIEITE_LANG_TYPE_##type && (XIEITE_LANG_MAJOR_##type == (major)) && (XIEITE_LANG_MINOR_##type == (minor)) && (XIEITE_LANG_PATCH_##type == (patch)))
#	define DETAIL_XIEITE_LANG_LEAST(type, major, minor, patch) (XIEITE_LANG_TYPE_##type && ((XIEITE_LANG_MAJOR_##type > (major)) || (XIEITE_LANG_MAJOR_##type == (major)) && ((XIEITE_LANG_MINOR_##type > (minor)) || (XIEITE_LANG_MINOR_##type == (minor)) && (XIEITE_LANG_PATCH_##type >= (patch)))))
#	define DETAIL_XIEITE_LANG_MOST(type, major, minor, patch) (XIEITE_LANG_TYPE_##type && ((XIEITE_LANG_MAJOR_##type < (major)) || (XIEITE_LANG_MAJOR_##type == (major)) && ((XIEITE_LANG_MINOR_##type < (minor)) || (XIEITE_LANG_MINOR_##type == (minor)) && (XIEITE_LANG_PATCH_##type <= (patch)))))
#
#	if defined(__STDC__) || defined(__STDC_VERSION__)
#		undef XIEITE_LANG_TYPE_C
#		define XIEITE_LANG_TYPE_C 1
#
#		undef XIEITE_LANG_MAJOR_C
#		ifndef __STDC_VERSION__
#			define XIEITE_LANG_MAJOR_C 1990
#		elif __STDC_VERSION__ <= 199409
#			define XIEITE_LANG_MAJOR_C 1995
#		elif __STDC_VERSION__ <= 199901
#			define XIEITE_LANG_MAJOR_C 1999
#		elif __STDC_VERSION__ <= 201112
#			define XIEITE_LANG_MAJOR_C 2011
#		elif __STDC_VERSION__ <= 201710
#			define XIEITE_LANG_MAJOR_C 2017
#		elif __STDC_VERSION__ <= 202311
#			define XIEITE_LANG_MAJOR_C 2023
#		else
#			define XIEITE_LANG_MAJOR_C 2026
#		endif
#	endif
#
#	ifdef __cplusplus
#		undef XIEITE_LANG_TYPE_CPP
#		define XIEITE_LANG_TYPE_CPP 1
#
#		ifdef _MSVC_LANG
#			define DETAIL_XIEITE_LANG_CPP _MSVC_LANG
#		else
#			define DETAIL_XIEITE_LANG_CPP __cplusplus
#		endif
#		undef XIEITE_LANG_MAJOR_CPP
#		if DETAIL_XIEITE_LANG_CPP <= 199711
#			define XIEITE_LANG_MAJOR_CPP 2003
#		elif DETAIL_XIEITE_LANG_CPP <= 201103
#			define XIEITE_LANG_MAJOR_CPP 2011
#		elif DETAIL_XIEITE_LANG_CPP <= 201402
#			define XIEITE_LANG_MAJOR_CPP 2014
#		elif DETAIL_XIEITE_LANG_CPP <= 201703
#			define XIEITE_LANG_MAJOR_CPP 2017
#		elif DETAIL_XIEITE_LANG_CPP <= 202002
#			define XIEITE_LANG_MAJOR_CPP 2020
#		elif DETAIL_XIEITE_LANG_CPP <= 202302
#			define XIEITE_LANG_MAJOR_CPP 2023
#		else
#			define XIEITE_LANG_MAJOR_CPP 2026
#		endif
#	endif
#
#	ifdef __cplusplus_cli
#		undef XIEITE_LANG_TYPE_CPP_CLI
#		define XIEITE_LANG_TYPE_CPP_CLI 1
#	endif
#
#	ifdef __cplusplus_winrt
#		undef XIEITE_LANG_TYPE_CPP_CX
#		define XIEITE_LANG_TYPE_CPP_CX 1
#	endif
#
#	ifdef __embedded_cplusplus
#		undef XIEITE_LANG_TYPE_CPP_EMBEDDED
#		define XIEITE_LANG_TYPE_CPP_EMBEDDED 1
#	endif
#
#	ifdef CPPWINRT_VERSION
#		undef XIEITE_LANG_TYPE_CPP_WINRT
#		define XIEITE_LANG_TYPE_CPP_WINRT 1
#	endif
#
#	if defined(__CUDA__) || defined(__CUDACC__)
#		include <cuda.h>
#
#		undef XIEITE_LANG_TYPE_CUDA
#		define XIEITE_LANG_TYPE_CUDA 1
#
#		ifdef CUDA_VERSION
#			undef XIEITE_LANG_MAJOR_CUDA
#			define XIEITE_LANG_MAJOR_CUDA (CUDA_VERSION / 1000)
#
#			undef XIEITE_LANG_MINOR_CUDA
#			define XIEITE_LANG_MINOR_CUDA (CUDA_VERSION % 1000 / 10)
#
#			undef XIEITE_LANG_PATCH_CUDA
#			define XIEITE_LANG_PATCH_CUDA (CUDA_VERSION % 10)
#		endif
#	endif
#
#	ifdef __GLSL__
#		undef XIEITE_LANG_TYPE_GLSL
#		define XIEITE_LANG_TYPE_GLSL 1
#
#		ifdef GLSL_VERSION
#			undef XIEITE_LANG_MAJOR_GLSL
#			define XIEITE_LANG_MAJOR_GLSL (GLSL_VERSION / 100)
#
#			undef XIEITE_LANG_MINOR_GLSL
#			define XIEITE_LANG_MINOR_GLSL (GLSL_VERSION % 100 / 10)
#		endif
#	endif
#
#	ifdef __HLSL__
#		undef XIEITE_LANG_TYPE_HLSL
#		define XIEITE_LANG_TYPE_HLSL 1
#
#		ifdef __HLSL_VERSION
#			undef XIEITE_LANG_MAJOR_HLSL
#			define XIEITE_LANG_MAJOR_HLSL __HLSL_VERSION
#		endif
#	endif
#
#	ifdef __METAL__
#		undef XIEITE_LANG_TYPE_METAL
#		define XIEITE_LANG_TYPE_METAL 1
#	endif
#
#	ifdef __OBJC__
#		undef XIEITE_LANG_TYPE_OBJECTIVE_C
#		define XIEITE_LANG_TYPE_OBJECTIVE_C 1
#	endif
#
#	ifdef __PSSL__
#		undef XIEITE_LANG_TYPE_PSSL
#		define XIEITE_LANG_TYPE_PSSL 1
#	endif
#endif

// https://github.com/cpredef/predef/blob/master/Standards.md#language-standards
// https://github.com/Microsoft/cppwinrt/issues/338
// https://github.com/Pikachuxxxx/Razix/blob/dd04eebd52c5989835d233bc59d0e2f18ecd3bb2/Engine/content/Shaders/ShaderCommon/ShaderInclude.Builtin.ShaderLangCommon.h
