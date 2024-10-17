#pragma once

#include <xieite/architecture.hpp>
#include <xieite/platform.hpp>

#define XIEITE_ENDIAN_BIG 0
#define XIEITE_ENDIAN_LITTLE 0
#define XIEITE_ENDIAN_BIG_WORD 0
#define XEIITE_ENDIAN_LITTLE_WORD 0

#if __has_include(<endian.h>)
#	include <endian.h>
#endif

#if __has_include(<machine/endian.h>)
#	include <machine/endian.h>
#endif

#if __has_include(<sys/param.h>)
#	include <sys/param.h>
#endif

#if __has_include(<sys/_endian.h>)
#	include <sys/_endian.h>
#endif

#if defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN) || defined(BIG_ENDIAN) || defined(_BIG_ENDIAN) || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__) || defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__) || defined(sel) || XIEITE_ARCHITECTURE_TYPE_BLUEFIN || XIEITE_ARCHITECTURE_TYPE_ITANIUM || XIEITE_ARCHITECTURE_TYPE_ELBRUS_2000 || XIEITE_ARCHITECTURE_TYPE_MIPS || XIEITE_ARCHITECTURE_TYPE_MOTOROLA_68000 || XIEITE_ARCHITECTURE_TYPE_POWERPC || XIEITE_ARCHITECTURE_TYPE_SPARC || XIEITE_PLATFORM_TYPE_AIX || XIEITE_PLATFORM_TYPE_CYGWIN || XIEITE_PLATFORM_TYPE_HP_UX || XIEITE_PLATFORM_TYPE_IRIX || XIEITE_PLATFORM_TYPE_SOLARIS || XIEITE_PLATFORM_TYPE_WINDOWS
#	undef XIEITE_ENDIAN_BIG
#	define XIEITE_ENDIAN_BIG 1
#endif

#if defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN) || defined(LITTLE_ENDIAN) || defined(_LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__) || XIEITE_ARCHITECTURE_TYPE_ALPHA || XIEITE_ARCHITECTURE_TYPE_ARM || XIEITE_ARCHITECTURE_TYPE_PA_RISC || XIEITE_ARCHITECTURE_TYPE_X86_32 || XIEITE_ARCHITECTURE_TYPE_X86_64 || XIEITE_ARCHITECTURE_TYPE_Z
#	undef XIEITE_ENDIAN_LITTLE
#	define XIEITE_ENDIAN_LITTLE 1
#endif

#if defined(__BYTE_ORDER) && (__BYTE_ORDER == __PDP_ENDIAN)
#	undef XIEITE_ENDIAN_LITTLE_WORD
#	define XIEITE_ENDIAN_LITTLE_WORD 1
#endif

// https://sourceforge.net/p/predef/wiki/Endianness/
// https://github.com/isar/libmdbx/blob/9fa76a56fcb548f539094d2168e5cb3406d4e7e1/src/preface.h#L520-L541
