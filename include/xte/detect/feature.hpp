#ifndef DETAIL_XTE_HEADER_DETECT_FEATURE
#	define DETAIL_XTE_HEADER_DETECT_FEATURE
#
#	include "../detect/compiler.hpp"
#	include "../detect/lang.hpp"
#	include "../preproc/util.hpp"
#
#	ifdef __has_include
#		define XTE_HAS_INCLUDE(INCLUDE) __has_include(INCLUDE)
#	else
#		define XTE_HAS_INCLUDE(INCLUDE) 0
#	endif
#
#	if XTE_LANG(CPP, >=, 2020)
#		define XTE_HAS_ATTR(NAME) __has_cpp_attribute(NAME)
#	elif XTE_LANG(C, >=, 2023)
#		define XTE_HAS_ATTR(NAME) __has_c_attribute(NAME)
#	elif XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_HAS_ATTR(NAME) __has_attribute(NAME)
#	else
#		define XTE_HAS_ATTR(NAME) 0
#	endif
#
#	if XTE_COMPILER_GCC || XTE_COMPILER_CLANG
#		define XTE_HAS_BUILTIN(NAME) __has_builtin(__builtin_##NAME)
#	else
#		define XTE_HAS_BUILTIN(NAME) 0
#	endif
#
#	if XTE_HAS_INCLUDE(<cstdint>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#
#	define XTE_HAS_INT_PTR 0
#	define XTE_HAS_INT_8 0
#	define XTE_HAS_INT_16 0
#	define XTE_HAS_INT_32 0
#	define XTE_HAS_INT_64 0
#	define XTE_HAS_INT_128 0
#	define XTE_HAS_FLOAT_16 0
#	define XTE_HAS_FLOAT_32 0
#	define XTE_HAS_FLOAT_64 0
#	define XTE_HAS_FLOAT_128 0
#	define XTE_HAS_BFLOAT_16 0
#	define XTE_HAS_SEQ_ITER 0
#
#	ifdef INTPTR_MAX
#		undef XTE_HAS_INT_PTR
#		define XTE_HAS_INT_PTR 1
#	endif
#
#	ifdef INT8_MAX
#		undef XTE_HAS_INT_8
#		define XTE_HAS_INT_8 1
#	endif
#
#	ifdef INT16_MAX
#		undef XTE_HAS_INT_16
#		define XTE_HAS_INT_16 1
#	endif
#
#	ifdef INT32_MAX
#		undef XTE_HAS_INT_32
#		define XTE_HAS_INT_32 1
#	endif
#
#	ifdef INT64_MAX
#		undef XTE_HAS_INT_64
#		define XTE_HAS_INT_64 1
#	endif
#
#	ifdef __SIZEOF_INT128__
#		undef XTE_HAS_INT_128
#		define XTE_HAS_INT_128 1
#	endif
#
#	ifdef __STDCPP_FLOAT16_T__
#		undef XTE_HAS_FLOAT_16
#		define XTE_HAS_FLOAT_16 1
#	endif
#
#	ifdef __STDCPP_FLOAT32_T__
#		undef XTE_HAS_FLOAT_32
#		define XTE_HAS_FLOAT_32 1
#	endif
#
#	ifdef __STDCPP_FLOAT64_T__
#		undef XTE_HAS_FLOAT_64
#		define XTE_HAS_FLOAT_64 1
#	endif
#
#	ifdef __STDCPP_FLOAT128_T__
#		undef XTE_HAS_FLOAT_128
#		define XTE_HAS_FLOAT_128 1
#	endif
#
#	ifdef __STDCPP_BFLOAT16_T__
#		undef XTE_HAS_BFLOAT_16
#		define XTE_HAS_BFLOAT_16 1
#	endif
#
#	define DETAIL_XTE_HAS_SEQ_ITER() DETAIL_XTE_HAS_SEQ_ITER_
#	define DETAIL_XTE_HAS_SEQ_ITER_() DETAIL_XTE_HAS_SEQ_ITER
#	define DETAIL_XTE_HAS_SEQ_ITER_DETAIL_XTE_HAS_SEQ_ITER() 0
#	define DETAIL_XTE_HAS_SEQ_ITER_DETAIL_XTE_HAS_SEQ_ITER_ 1
#	if XTE_CAT(DETAIL_XTE_HAS_SEQ_ITER_, DETAIL_XTE_HAS_SEQ_ITER()()())
#		undef XTE_HAS_SEQ_ITER
#		define XTE_HAS_SEQ_ITER 1
#	endif
#endif
