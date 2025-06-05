#ifndef DETAIL_XIEITE_HEADER_PP_FEAT
#	define DETAIL_XIEITE_HEADER_PP_FEAT
#
#	include "../pp/compiler.hpp"
#	include "../pp/diagnostic.hpp"
#
#	if __has_include(<cstdint>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#
#	define XIEITE_FEAT_TRIGRAPHS 0
#	define XIEITE_FEAT_I8 0
#	define XIEITE_FEAT_U8 0
#	define XIEITE_FEAT_I16 0
#	define XIEITE_FEAT_U16 0
#	define XIEITE_FEAT_I32 0
#	define XIEITE_FEAT_U32 0
#	define XIEITE_FEAT_I64 0
#	define XIEITE_FEAT_U64 0
#	define XIEITE_FEAT_I128 0
#	define XIEITE_FEAT_U128 0
#	define XIEITE_FEAT_F16 0
#	define XIEITE_FEAT_F32 0
#	define XIEITE_FEAT_F64 0
#	define XIEITE_FEAT_F128 0
#	define XIEITE_FEAT_FBRAIN 0
#	define XIEITE_FEAT_BASED_PTR 0

XIEITE_DIAGNOSTIC_PUSH_GCC()
XIEITE_DIAGNOSTIC_OFF_GCC("-Wtrigraphs")
XIEITE_DIAGNOSTIC_OFF_GCC("-Wcomment")
#	if 1 // ??/
#	else
#		undef XIEITE_FEAT_TRIGRAPHS
#		define XIEITE_FEAT_TRIGRAPHS 1
#	endif
XIEITE_DIAGNOSTIC_POP_GCC()


#	ifdef INT8_MAX
#		undef XIEITE_FEAT_I8
#		define XIEITE_FEAT_I8 1
#	endif
#
#	ifdef INT16_MAX
#		undef XIEITE_FEAT_I16
#		define XIEITE_FEAT_I16 1
#	endif
#
#	ifdef INT32_MAX
#		undef XIEITE_FEAT_I32
#		define XIEITE_FEAT_I32 1
#	endif
#
#	ifdef INT64_MAX
#		undef XIEITE_FEAT_I64
#		define XIEITE_FEAT_I64 1
#	endif
#
#	if defined(__SIZEOF_INT128__) || XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_FEAT_I128
#		define XIEITE_FEAT_I128 1
#	endif
#
#	ifdef __STDCPP_FLOAT16_T__
#		undef XIEITE_FEAT_F16
#		define XIEITE_FEAT_F16 1
#	endif
#
#	ifdef __STDCPP_FLOAT32_T__
#		undef XIEITE_FEAT_F32
#		define XIEITE_FEAT_F32 1
#	endif
#
#	ifdef __STDCPP_FLOAT64_T__
#		undef XIEITE_FEAT_F64
#		define XIEITE_FEAT_F64 1
#	endif
#
#	ifdef __STDCPP_FLOAT128_T__
#		undef XIEITE_FEAT_F128
#		define XIEITE_FEAT_F128 1
#	endif
#
#	ifdef __STDCPP_BFLOAT16_T__
#		undef XIEITE_FEAT_FBRAIN
#		define XIEITE_FEAT_FBRAIN 1
#	endif
#
#	if XIEITE_COMPILER_TYPE_MSVC
#		undef XIEITE_FEAT_BASED_PTR
#		define XIEITE_FEAT_BASED_PTR 1
#	endif
#endif
