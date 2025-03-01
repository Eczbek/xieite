#pragma once

#include "../pp/arch.hpp"
#include "../pp/pltf.hpp"

#define X4ENDIAN_BIG 0
#define X4ENDIAN_LITTLE 0
#define X4ENDIAN_BIGWORD 0
#define X4ENDIAN_LITTLEWORD 0

#if __has_include(<endian.h>)
#	include <endian.h>
#endif

#if __has_include(<libkern/OSByteOrder.h>)
#	include <libkern/OSByteOrder.h>
#endif

#if __has_include(<machine/endian.h>)
#	include <machine/endian.h>
#endif

#if __has_include(<sys/endian.h>)
#	include <sys/endian.h>
#endif

#if __has_include(<sys/_endian.h>)
#	include <sys/_endian.h>
#endif

#if __has_include(<sys/param.h>)
#	include <sys/param.h>
#endif

#if __has_include(<sys/types.h>)
#	include <sys/types.h>
#endif

#if __has_include(<winsock2.h>)
#	include <winsock2.h>
#endif

#if defined(BIG_ENDIAN) || defined(_BIG_ENDIAN) || defined(_MIPSEB) || defined(__AARCH64EB__) || defined(__ARMEB__) || defined(__BIG_ENDIAN__) || (defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN)) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)) || (defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__)) || defined(__MIPSEB) || defined(__MIPSEB__) || defined(__THUMBEB__) || defined(sel) || X4ARCH_ELBRUS_2000 || X4ARCH_IBM_SYSTEM_370 || X4ARCH_IBM_SYSTEM_390 || X4ARCH_IBM_Z || X4ARCH_MOTOROLA_68000 || X4ARCH_PA_RISC || X4ARCH_POWERPC || X4ARCH_SPARC || X4PLTF_AIX || X4PLTF_CYGWIN || X4PLTF_HP_UX || X4PLTF_IRIX || X4PLTF_SOLARIS || X4PLTF_WINDOWS
#	undef X4ENDIAN_BIG
#	define X4ENDIAN_BIG 1
#endif

#if defined(LITTLE_ENDIAN) || defined(_LITTLE_ENDIAN) || defined(_MIPSEL) || defined(__AARCH64EL__) || defined(__ARMEL__) || (defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN)) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)) || (defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__)) || defined(__LITTLE_ENDIAN__) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(__THUMBEL__) || X4ARCH_ALPHA || X4ARCH_ARM || X4ARCH_BLACKFIN || X4ARCH_ELBRUS_2000 || X4ARCH_IA64 || X4ARCH_X86_32 || X4ARCH_X86_64 || X4PLTF_CYGWIN || X4PLTF_WINDOWS
#	undef X4ENDIAN_LITTLE
#	define X4ENDIAN_LITTLE 1
#endif

#if defined(__BYTE_ORDER) && (__BYTE_ORDER == __PDP_ENDIAN)
#	undef X4ENDIAN_LITTLEWORD
#	define X4ENDIAN_LITTLEWORD 1
#endif
