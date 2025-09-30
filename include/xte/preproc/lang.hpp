#ifndef DETAIL_XTE_HEADER_PREPROC_LANG
#	define DETAIL_XTE_HEADER_PREPROC_LANG
#
#	define XTE_LANG_TYPE_C 0
#	define XTE_LANG_MAJOR_C 0
#	define XTE_LANG_MINOR_C 0
#	define XTE_LANG_PATCH_C 0
#	define XTE_LANG_TYPE_CPP 0
#	define XTE_LANG_MAJOR_CPP 0
#	define XTE_LANG_MINOR_CPP 0
#	define XTE_LANG_PATCH_CPP 0
#	define XTE_LANG_TYPE_CPP_CLI 0
#	define XTE_LANG_MAJOR_CPP_CLI 0
#	define XTE_LANG_MINOR_CPP_CLI 0
#	define XTE_LANG_PATCH_CPP_CLI 0
#	define XTE_LANG_TYPE_CPP_CX 0
#	define XTE_LANG_MAJOR_CPP_CX 0
#	define XTE_LANG_MINOR_CPP_CX 0
#	define XTE_LANG_PATCH_CPP_CX 0
#	define XTE_LANG_TYPE_CPP_EMBEDDED 0
#	define XTE_LANG_MAJOR_CPP_EMBEDDED 0
#	define XTE_LANG_MINOR_CPP_EMBEDDED 0
#	define XTE_LANG_PATCH_CPP_EMBEDDED 0
#	define XTE_LANG_TYPE_CPP_WINRT 0
#	define XTE_LANG_MAJOR_CPP_WINRT 0
#	define XTE_LANG_MINOR_CPP_WINRT 0
#	define XTE_LANG_PATCH_CPP_WINRT 0
#	define XTE_LANG_TYPE_CUDA 0
#	define XTE_LANG_MAJOR_CUDA 0
#	define XTE_LANG_MINOR_CUDA 0
#	define XTE_LANG_PATCH_CUDA 0
#	define XTE_LANG_TYPE_GLSL 0
#	define XTE_LANG_MAJOR_GLSL 0
#	define XTE_LANG_MINOR_GLSL 0
#	define XTE_LANG_PATCH_GLSL 0
#	define XTE_LANG_TYPE_HLSL 0
#	define XTE_LANG_MAJOR_HLSL 0
#	define XTE_LANG_MINOR_HLSL 0
#	define XTE_LANG_PATCH_HLSL 0
#	define XTE_LANG_TYPE_METAL 0
#	define XTE_LANG_MAJOR_METAL 0
#	define XTE_LANG_MINOR_METAL 0
#	define XTE_LANG_PATCH_METAL 0
#	define XTE_LANG_TYPE_OBJ_C 0
#	define XTE_LANG_MAJOR_OBJ_C 0
#	define XTE_LANG_MINOR_OBJ_C 0
#	define XTE_LANG_PATCH_OBJ_C 0
#	define XTE_LANG_TYPE_OBJ_CPP 0
#	define XTE_LANG_MAJOR_OBJ_CPP 0
#	define XTE_LANG_MINOR_OBJ_CPP 0
#	define XTE_LANG_PATCH_OBJ_CPP 0
#	define XTE_LANG_TYPE_PSSL 0
#	define XTE_LANG_MAJOR_PSSL 0
#	define XTE_LANG_MINOR_PSSL 0
#	define XTE_LANG_PATCH_PSSL 0
#	define XTE_LANG_VERSION(_type, _op, _major, ...) DETAIL_XTE_LANG_VERSION(_op, XTE_LANG_MAJOR_##_type, XTE_LANG_MINOR_##_type, XTE_LANG_PATCH_##_type, _major, __VA_ARGS__ __VA_OPT__(,) 0, 0)
#
#	define DETAIL_XTE_LANG_VERSION(_op, _major0, _minor0, _patch0, _major1, _minor1, _patch1, ...) (((((0 _op 0) && !(0 _op 1) && !(1 _op 0)) || (!(0 _op 0) && (0 _op 1) && (1 _op 0))) && (((_major0) _op (_major1)) && ((_minor0) _op (_minor1)) && ((_patch0) _op (_patch1)))) || ((_major0) _op (_major1)) || (((_major0) == (_major1)) && ((_minor0) _op (_minor1))) || (((_minor0) == (_minor1)) && ((_patch0) _op (_patch1))))
#
#	if defined(__STDC__) || defined(__STDC_VERSION__)
#		undef XTE_LANG_TYPE_C
#		define XTE_LANG_TYPE_C 1
#
#		undef XTE_LANG_MAJOR_C
#		if __STDC_VERSION__ > 202311
#			define XTE_LANG_MAJOR_C 2026
#		elif __STDC_VERSION__ > 201710
#			define XTE_LANG_MAJOR_C 2023
#		elif __STDC_VERSION__ > 201112
#			define XTE_LANG_MAJOR_C 2017
#		elif __STDC_VERSION__ > 199901
#			define XTE_LANG_MAJOR_C 2011
#		elif __STDC_VERSION__ > 199409
#			define XTE_LANG_MAJOR_C 1999
#		elifdef __STDC_VERSION__
#			define XTE_LANG_MAJOR_C 1995
#		else
#			define XTE_LANG_MAJOR_C 1990
#		endif
#	endif
#
#	ifdef __cplusplus
#		undef XTE_LANG_TYPE_CPP
#		define XTE_LANG_TYPE_CPP 1
#
#		ifdef _MSVC_LANG
#			define DETAIL_XTE_LANG_CPP _MSVC_LANG
#		else
#			define DETAIL_XTE_LANG_CPP __cplusplus
#		endif
#		undef XTE_LANG_MAJOR_CPP
#		if DETAIL_XTE_LANG_CPP > 202302
#			define XTE_LANG_MAJOR_CPP 2026
#		elif DETAIL_XTE_LANG_CPP > 202002
#			define XTE_LANG_MAJOR_CPP 2023
#		elif DETAIL_XTE_LANG_CPP > 201703
#			define XTE_LANG_MAJOR_CPP 2020
#		elif DETAIL_XTE_LANG_CPP > 201402
#			define XTE_LANG_MAJOR_CPP 2017
#		elif DETAIL_XTE_LANG_CPP > 201103
#			define XTE_LANG_MAJOR_CPP 2014
#		elif DETAIL_XTE_LANG_CPP > 199711
#			define XTE_LANG_MAJOR_CPP 2011
#		else
#			define XTE_LANG_MAJOR_CPP 1998
#		endif
#	endif
#
#	ifdef __cplusplus_cli
#		undef XTE_LANG_TYPE_CPP_CLI
#		define XTE_LANG_TYPE_CPP_CLI 1
#	endif
#
#	ifdef __cplusplus_winrt
#		undef XTE_LANG_TYPE_CPP_CX
#		define XTE_LANG_TYPE_CPP_CX 1
#	endif
#
#	ifdef __embedded_cplusplus
#		undef XTE_LANG_TYPE_CPP_EMBEDDED
#		define XTE_LANG_TYPE_CPP_EMBEDDED 1
#	endif
#
#	ifdef CPPWINRT_VERSION
#		undef XTE_LANG_TYPE_CPP_WINRT
#		define XTE_LANG_TYPE_CPP_WINRT 1
#	endif
#
#	if defined(__CUDA__) || defined(__CUDACC__)
#		include <cuda.h>
#
#		undef XTE_LANG_TYPE_CUDA
#		define XTE_LANG_TYPE_CUDA 1
#
#		ifdef CUDA_VERSION
#			undef XTE_LANG_MAJOR_CUDA
#			define XTE_LANG_MAJOR_CUDA (CUDA_VERSION / 1000)
#
#			undef XTE_LANG_MINOR_CUDA
#			define XTE_LANG_MINOR_CUDA (CUDA_VERSION % 1000 / 10)
#
#			undef XTE_LANG_PATCH_CUDA
#			define XTE_LANG_PATCH_CUDA (CUDA_VERSION % 10)
#		endif
#	endif
#
#	ifdef __GLSL__
#		undef XTE_LANG_TYPE_GLSL
#		define XTE_LANG_TYPE_GLSL 1
#
#		ifdef GLSL_VERSION
#			undef XTE_LANG_MAJOR_GLSL
#			define XTE_LANG_MAJOR_GLSL (GLSL_VERSION / 100)
#
#			undef XTE_LANG_MINOR_GLSL
#			define XTE_LANG_MINOR_GLSL (GLSL_VERSION % 100 / 10)
#		endif
#	endif
#
#	ifdef __HLSL__
#		undef XTE_LANG_TYPE_HLSL
#		define XTE_LANG_TYPE_HLSL 1
#
#		ifdef __HLSL_VERSION
#			undef XTE_LANG_MAJOR_HLSL
#			define XTE_LANG_MAJOR_HLSL __HLSL_VERSION
#		endif
#	endif
#
#	ifdef __METAL__
#		undef XTE_LANG_TYPE_METAL
#		define XTE_LANG_TYPE_METAL 1
#	endif
#
#	if defined(__OBJC__) || defined(__OBJC2__)
#		undef XTE_LANG_TYPE_OBJ_C
#		define XTE_LANG_TYPE_OBJ_C 1
#
#		undef XTE_LANG_MAJOR_OBJ_C
#		ifdef __OBJC2__
#			define XTE_LANG_MAJOR_OBJ_C 2
#		else
#			define XTE_LANG_MAJOR_OBJ_C 1
#		endif
#	endif
#
#	if ((defined(__OBJC__) || defined(__OBJC2__)) && defined(__cplusplus)) || defined(__OBJCPP__)
#		undef XTE_LANG_TYPE_OBJ_CPP
#		define XTE_LANG_TYPE_OBJ_CPP 1
#
#		undef XTE_LANG_MAJOR_OBJ_CPP
#		ifdef __OBJC2__
#			define XTE_LANG_MAJOR_OBJ_CPP 2
#		else
#			define XTE_LANG_MAJOR_OBJ_CPP 1
#		endif
#	endif
#
#	ifdef __PSSL__
#		undef XTE_LANG_TYPE_PSSL
#		define XTE_LANG_TYPE_PSSL 1
#	endif
#endif

// https://github.com/cpredef/predef/blob/master/Standards.md#language-standards
// https://github.com/Microsoft/cppwinrt/issues/338
// https://github.com/Pikachuxxxx/Razix/blob/dd04eebd52c5989835d233bc59d0e2f18ecd3bb2/Engine/content/Shaders/ShaderCommon/ShaderInclude.Builtin.ShaderLangCommon.h
