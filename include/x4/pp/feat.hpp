#pragma once

#include "../pp/cplr.hpp"

#if __has_include(<cstdint>)
#	include <cstdint>
#else
#	include <stdint.h>
#endif

#define X4FEAT_I8 0
#define X4FEAT_U8 0
#define X4FEAT_I16 0
#define X4FEAT_U16 0
#define X4FEAT_I32 0
#define X4FEAT_U32 0
#define X4FEAT_I64 0
#define X4FEAT_U64 0
#define X4FEAT_I128 0
#define X4FEAT_U128 0
#define X4FEAT_F16 0
#define X4FEAT_F32 0
#define X4FEAT_F64 0
#define X4FEAT_F128 0
#define X4FEAT_FBRAIN 0
#define X4FEAT_BASEDPTR 0


#ifdef INT8_MAX
#	undef X4FEAT_I8
#	define X4FEAT_I8 1
#endif

#ifdef INT16_MAX
#	undef X4FEAT_I16
#	define X4FEAT_I16 1
#endif

#ifdef INT32_MAX
#	undef X4FEAT_I32
#	define X4FEAT_I32 1
#endif

#ifdef INT64_MAX
#	undef X4FEAT_I64
#	define X4FEAT_I64 1
#endif

#if defined(__SIZEOF_INT128__) || X4CPLR_MSVC
#	undef X4FEAT_I128
#	define X4FEAT_I128 1
#endif

#ifdef __STDCPP_FLOAT16_T__
#	undef X4FEAT_F16
#	define X4FEAT_F16 1
#endif

#ifdef __STDCPP_FLOAT32_T__
#	undef X4FEAT_F32
#	define X4FEAT_F32 1
#endif

#ifdef __STDCPP_FLOAT64_T__
#	undef X4FEAT_F64
#	define X4FEAT_F64 1
#endif

#ifdef __STDCPP_FLOAT128_T__
#	undef X4FEAT_F128
#	define X4FEAT_F128 1
#endif

#ifdef __STDCPP_BFLOAT16_T__
#	undef X4FEAT_FBRAIN
#	define X4FEAT_FBRAIN 1
#endif

#if X4CPLR_MSVC
#	undef X4FEAT_BASEDPTR
#	define X4FEAT_BASEDPTR 1
#endif
