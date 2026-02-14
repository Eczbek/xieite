#ifndef DETAIL_XTE_HEADER_PREPROC_LANG
#	define DETAIL_XTE_HEADER_PREPROC_LANG
#
#	define XTE_LANG_C 0
#	define XTE_LANG_C_MAJOR 0
#	define XTE_LANG_C_MINOR 0
#	define XTE_LANG_C_PATCH 0
#	define XTE_LANG_CPP 0
#	define XTE_LANG_CPP_MAJOR 0
#	define XTE_LANG_CPP_MINOR 0
#	define XTE_LANG_CPP_PATCH 0
#	define XTE_LANG_CPP_CLI 0
#	define XTE_LANG_CPP_CLI_MAJOR 0
#	define XTE_LANG_CPP_CLI_MINOR 0
#	define XTE_LANG_CPP_CLI_PATCH 0
#	define XTE_LANG_CPP_CX 0
#	define XTE_LANG_CPP_CX_MAJOR 0
#	define XTE_LANG_CPP_CX_MINOR 0
#	define XTE_LANG_CPP_CX_PATCH 0
#	define XTE_LANG_CPP_EMBEDDED 0
#	define XTE_LANG_CPP_EMBEDDED_MAJOR 0
#	define XTE_LANG_CPP_EMBEDDED_MINOR 0
#	define XTE_LANG_CPP_EMBEDDED_PATCH 0
#	define XTE_LANG_CPP_WINRT 0
#	define XTE_LANG_CPP_WINRT_MAJOR 0
#	define XTE_LANG_CPP_WINRT_MINOR 0
#	define XTE_LANG_CPP_WINRT_PATCH 0
#	define XTE_LANG_CUDA 0
#	define XTE_LANG_CUDA_MAJOR 0
#	define XTE_LANG_CUDA_MINOR 0
#	define XTE_LANG_CUDA_PATCH 0
#	define XTE_LANG_GLSL 0
#	define XTE_LANG_GLSL_MAJOR 0
#	define XTE_LANG_GLSL_MINOR 0
#	define XTE_LANG_GLSL_PATCH 0
#	define XTE_LANG_HLSL 0
#	define XTE_LANG_HLSL_MAJOR 0
#	define XTE_LANG_HLSL_MINOR 0
#	define XTE_LANG_HLSL_PATCH 0
#	define XTE_LANG_METAL 0
#	define XTE_LANG_METAL_MAJOR 0
#	define XTE_LANG_METAL_MINOR 0
#	define XTE_LANG_METAL_PATCH 0
#	define XTE_LANG_OBJ_C 0
#	define XTE_LANG_OBJ_C_MAJOR 0
#	define XTE_LANG_OBJ_C_MINOR 0
#	define XTE_LANG_OBJ_C_PATCH 0
#	define XTE_LANG_OBJ_CPP 0
#	define XTE_LANG_OBJ_CPP_MAJOR 0
#	define XTE_LANG_OBJ_CPP_MINOR 0
#	define XTE_LANG_OBJ_CPP_PATCH 0
#	define XTE_LANG_PSSL 0
#	define XTE_LANG_PSSL_MAJOR 0
#	define XTE_LANG_PSSL_MINOR 0
#	define XTE_LANG_PSSL_PATCH 0
#
#	define XTE_LANG(_type, _operator, _major, ...) \
		DETAIL_XTE_LANG( \
			_operator, \
			XTE_LANG_##_type##_MAJOR, XTE_LANG_##_type##_MINOR, XTE_LANG_##_type##_PATCH, \
			_major, __VA_ARGS__ __VA_OPT__(,) 0, 0 \
		)
#
#	if defined(__STDC__) || defined(__STDC_VERSION__)
#		undef XTE_LANG_C
#		define XTE_LANG_C 1
#
#		undef XTE_LANG_C_MAJOR
#		if __STDC_VERSION__ > 202311
#			define XTE_LANG_C_MAJOR 2026
#		elif __STDC_VERSION__ > 201710
#			define XTE_LANG_C_MAJOR 2023
#		elif __STDC_VERSION__ > 201112
#			define XTE_LANG_C_MAJOR 2017
#		elif __STDC_VERSION__ > 199901
#			define XTE_LANG_C_MAJOR 2011
#		elif __STDC_VERSION__ > 199409
#			define XTE_LANG_C_MAJOR 1999
#		elifdef __STDC_VERSION__
#			define XTE_LANG_C_MAJOR 1995
#		else
#			define XTE_LANG_C_MAJOR 1990
#		endif
#	endif
#
#	ifdef __cplusplus
#		undef XTE_LANG_CPP
#		define XTE_LANG_CPP 1
#
#		ifdef _MSVC_LANG
#			define DETAIL_XTE_LANG_CPP _MSVC_LANG
#		else
#			define DETAIL_XTE_LANG_CPP __cplusplus
#		endif
#		undef XTE_LANG_CPP_MAJOR
#		if DETAIL_XTE_LANG_CPP > 202302
#			define XTE_LANG_CPP_MAJOR 2026
#		elif DETAIL_XTE_LANG_CPP > 202002
#			define XTE_LANG_CPP_MAJOR 2023
#		elif DETAIL_XTE_LANG_CPP > 201703
#			define XTE_LANG_CPP_MAJOR 2020
#		elif DETAIL_XTE_LANG_CPP > 201402
#			define XTE_LANG_CPP_MAJOR 2017
#		elif DETAIL_XTE_LANG_CPP > 201103
#			define XTE_LANG_CPP_MAJOR 2014
#		elif DETAIL_XTE_LANG_CPP > 199711
#			define XTE_LANG_CPP_MAJOR 2011
#		else
#			define XTE_LANG_CPP_MAJOR 1998
#		endif
#	endif
#
#	ifdef __cplusplus_cli
#		undef XTE_LANG_CPP_CLI
#		define XTE_LANG_CPP_CLI 1
#	endif
#
#	ifdef __cplusplus_winrt
#		undef XTE_LANG_CPP_CX
#		define XTE_LANG_CPP_CX 1
#	endif
#
#	ifdef __embedded_cplusplus
#		undef XTE_LANG_CPP_EMBEDDED
#		define XTE_LANG_CPP_EMBEDDED 1
#	endif
#
#	ifdef CPPWINRT_VERSION
#		undef XTE_LANG_CPP_WINRT
#		define XTE_LANG_CPP_WINRT 1
#	endif
#
#	if defined(__CUDA__) || defined(__CUDACC__)
#		include <cuda.h>
#
#		undef XTE_LANG_CUDA
#		define XTE_LANG_CUDA 1
#
#		ifdef CUDA_VERSION
#			undef XTE_LANG_CUDA_MAJOR
#			define XTE_LANG_CUDA_MAJOR (CUDA_VERSION / 1000)
#
#			undef XTE_LANG_CUDA_MINOR
#			define XTE_LANG_CUDA_MINOR (CUDA_VERSION % 1000 / 10)
#
#			undef XTE_LANG_CUDA_PATCH
#			define XTE_LANG_CUDA_PATCH (CUDA_VERSION % 10)
#		endif
#	endif
#
#	ifdef __GLSL__
#		undef XTE_LANG_GLSL
#		define XTE_LANG_GLSL 1
#
#		ifdef GLSL_VERSION
#			undef XTE_LANG_GLSL_MAJOR
#			define XTE_LANG_GLSL_MAJOR (GLSL_VERSION / 100)
#
#			undef XTE_LANG_GLSL_MINOR
#			define XTE_LANG_GLSL_MINOR (GLSL_VERSION % 100 / 10)
#		endif
#	endif
#
#	ifdef __HLSL__
#		undef XTE_LANG_HLSL
#		define XTE_LANG_HLSL 1
#
#		ifdef __HLSL_VERSION
#			undef XTE_LANG_HLSL_MAJOR
#			define XTE_LANG_HLSL_MAJOR __HLSL_VERSION
#		endif
#	endif
#
#	ifdef __METAL__
#		undef XTE_LANG_METAL
#		define XTE_LANG_METAL 1
#	endif
#
#	if defined(__OBJC__) || defined(__OBJC2__)
#		undef XTE_LANG_OBJ_C
#		define XTE_LANG_OBJ_C 1
#
#		undef XTE_LANG_OBJ_C_MAJOR
#		ifdef __OBJC2__
#			define XTE_LANG_OBJ_C_MAJOR 2
#		else
#			define XTE_LANG_OBJ_C_MAJOR 1
#		endif
#	endif
#
#	if ((defined(__OBJC__) || defined(__OBJC2__)) && defined(__cplusplus)) || defined(__OBJCPP__)
#		undef XTE_LANG_OBJ_CPP
#		define XTE_LANG_OBJ_CPP 1
#
#		undef XTE_LANG_OBJ_CPP_MAJOR
#		ifdef __OBJC2__
#			define XTE_LANG_OBJ_CPP_MAJOR 2
#		else
#			define XTE_LANG_OBJ_CPP_MAJOR 1
#		endif
#	endif
#
#	ifdef __PSSL__
#		undef XTE_LANG_PSSL
#		define XTE_LANG_PSSL 1
#	endif
#
#	define DETAIL_XTE_LANG(_operator, _major0, _minor0, _patch0, _major1, _minor1, _patch1, ...) \
		(((((0 _operator 0) && !(0 _operator 1) && !(1 _operator 0)) \
			|| (!(0 _operator 0) && (0 _operator 1) && (1 _operator 0))) \
		&& (((_major0) _operator (_major1)) \
			&& ((_minor0) _operator (_minor1)) \
			&& ((_patch0) _operator (_patch1)))) \
		|| ((_major0) _operator (_major1)) \
			|| (((_major0) == (_major1)) && ((_minor0) _operator (_minor1))) \
			|| (((_minor0) == (_minor1)) && ((_patch0) _operator (_patch1))))
#endif

// https://github.com/cpredef/predef/blob/master/Standards.md#language-standards
// https://github.com/Microsoft/cppwinrt/issues/338
// https://github.com/Pikachuxxxx/Razix/blob/dd04eebd52c5989835d233bc59d0e2f18ecd3bb2/Engine/content/Shaders/ShaderCommon/ShaderInclude.Builtin.ShaderLangCommon.h
