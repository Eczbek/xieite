#ifndef DETAIL_XTE_HEADER_PREPROC_FEATURE
#	define DETAIL_XTE_HEADER_PREPROC_FEATURE
#
#	if __has_include(<cstdint>)
#		include <cstdint>
#	else
#		include <stdint.h>
#	endif
#
#	define XTE_FEATURE_INT_8 0
#	define XTE_FEATURE_INT_16 0
#	define XTE_FEATURE_INT_32 0
#	define XTE_FEATURE_INT_64 0
#	define XTE_FEATURE_INT_128 0
#	define XTE_FEATURE_FLOAT_16 0
#	define XTE_FEATURE_FLOAT_32 0
#	define XTE_FEATURE_FLOAT_64 0
#	define XTE_FEATURE_FLOAT_128 0
#	define XTE_FEATURE_BFLOAT_16 0
#
#	ifdef INT8_MAX
#		undef XTE_FEATURE_INT_8
#		define XTE_FEATURE_INT_8 1
#	endif
#
#	ifdef INT16_MAX
#		undef XTE_FEATURE_INT_16
#		define XTE_FEATURE_INT_16 1
#	endif
#
#	ifdef INT32_MAX
#		undef XTE_FEATURE_INT_32
#		define XTE_FEATURE_INT_32 1
#	endif
#
#	ifdef INT64_MAX
#		undef XTE_FEATURE_INT_64
#		define XTE_FEATURE_INT_64 1
#	endif
#
#	ifdef __SIZEOF_INT128__
#		undef XTE_FEATURE_INT_128
#		define XTE_FEATURE_INT_128 1
#	endif
#
#	ifdef __STDCPP_FLOAT16_T__
#		undef XTE_FEATURE_FLOAT_16
#		define XTE_FEATURE_FLOAT_16 1
#	endif
#
#	ifdef __STDCPP_FLOAT32_T__
#		undef XTE_FEATURE_FLOAT_32
#		define XTE_FEATURE_FLOAT_32 1
#	endif
#
#	ifdef __STDCPP_FLOAT64_T__
#		undef XTE_FEATURE_FLOAT_64
#		define XTE_FEATURE_FLOAT_64 1
#	endif
#
#	ifdef __STDCPP_FLOAT128_T__
#		undef XTE_FEATURE_FLOAT_128
#		define XTE_FEATURE_FLOAT_128 1
#	endif
#
#	ifdef __STDCPP_BFLOAT16_T__
#		undef XTE_FEATURE_BFLOAT_16
#		define XTE_FEATURE_BFLOAT_16 1
#	endif
#endif
