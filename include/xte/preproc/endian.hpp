#ifndef DETAIL_XTE_HEADER_PREPROC_ENDIAN
#	define DETAIL_XTE_HEADER_PREPROC_ENDIAN
#
#	define XTE_ENDIAN_BIG 0
#	define XTE_ENDIAN_LITTLE 0
#	define XTE_ENDIAN_BIG_WORD 0 // Honeywell 316
#	define XTE_ENDIAN_LITTLE_WORD 0 // PDP-11
#
#	include "../preproc/arch.hpp"
#	include "../preproc/platform.hpp"
#
#	if __has_include(<endian.h>)
#		include <endian.h>
#	endif
#
#	if __has_include(<gulliver.h>)
#		include <gulliver.h>
#	endif
#
#	if __has_include(<libkern/OSByteOrder.h>)
#		include <libkern/OSByteOrder.h>
#	endif
#
#	if __has_include(<machine/endian.h>)
#		include <machine/endian.h>
#	endif
#
#	if __has_include(<sys/endian.h>)
#		include <sys/endian.h>
#	endif
#
#	if __has_include(<sys/isa_defs.h>)
#		include <sys/isa_defs.h>
#	endif
#
#	if __has_include(<sys/param.h>)
#		include <sys/param.h>
#	endif
#
#	if __has_include(<sys/types.h>)
#		include <sys/types.h>
#	endif
#
#	if __has_include(<sys/_endian.h>)
#		include <sys/_endian.h>
#	endif
#
#	if __has_include(<winsock2.h>)
#		include <winsock2.h>
#	endif
#
#	if (defined(BYTE_ORDER) && (BYTE_ORDER == BIG_ENDIAN)) \
		|| defined(_BIG_ENDIAN) \
		|| defined(_BIG_ENDIAN__) \
		|| defined(_MIPSEB) \
		|| defined(__AARCH64EB__) \
		|| defined(__ARC_LITTLE_ENDIAN__) \
		|| defined(__ARMEB__) \
		|| defined(__BIGENDIAN__) \
		|| defined(__BIG_ENDIAN__) \
		|| (defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN)) \
		|| defined(__BYTE_ORDER_BIG_ENDIAN__) \
		|| (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)) \
		|| (defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__)) \
		|| defined(__MICROBLAZEEB__) \
		|| defined(__MIPSEB) \
		|| defined(__MIPSEB__) \
		|| defined(__MOXIE_BIG_ENDIAN__) \
		|| defined(__RX_BIG_ENDIAN__) \
		|| defined(__THUMBEB__) \
		|| defined(__big_endian__) \
		|| defined(__nios2_big_endian__) \
		|| XTE_ARCH_AM29000 \
		|| XTE_ARCH_D10V \
		|| XTE_ARCH_D30V \
		|| XTE_ARCH_FUJITSU_FR_V \
		|| XTE_ARCH_FR30 \
		|| XTE_ARCH_IBM_SYSTEM_370 \
		|| XTE_ARCH_IBM_SYSTEM_390 \
		|| XTE_ARCH_IBM_Z \
		|| XTE_ARCH_IP2000 \
		|| XTE_ARCH_IQ2000 \
		|| XTE_ARCH_LATTICEMICO32 \
		|| XTE_ARCH_M32R \
		|| XTE_ARCH_MMIX \
		|| XTE_ARCH_MOTOROLA_68000 \
		|| XTE_ARCH_MOTOROLA_88000 \
		|| XTE_ARCH_MOTOROLA_HC11 \
		|| XTE_ARCH_MOTOROLA_M_CORE \
		|| XTE_ARCH_OPENRISC \
		|| XTE_ARCH_PA_RISC \
		|| (XTE_ARCH_POWERPC && !defined(__PPC64LE__) && !defined(__ppc64le__)) \
		|| XTE_ARCH_SPARC \
		|| XTE_PLATFORM_AIX \
		|| XTE_PLATFORM_IRIX \
		|| XTE_PLATFORM_SOLARIS
#		undef XTE_ENDIAN_BIG
#		define XTE_ENDIAN_BIG 1
#	endif
#
#	if (defined(BYTE_ORDER) && (BYTE_ORDER == LITTLE_ENDIAN)) \
		|| defined(_LITTLE_ENDIAN) \
		|| defined(_LITTLE_ENDIAN__) \
		|| defined(_MIPSEL) \
		|| defined(__AARCH64EL__) \
		|| defined(__ARC_LITTLE_ENDIAN__) \
		|| defined(__ARMEL__) \
		|| (defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN)) \
		|| defined(__BYTE_ORDER_LITTLE_ENDIAN__) \
		|| (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)) \
		|| (defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__)) \
		|| defined(__LITTLEENDIAN__) \
		|| defined(__LITTLE_ENDIAN__) \
		|| defined(__MICROBLAZEEL__) \
		|| defined(__MIPSEL) \
		|| defined(__MIPSEL__) \
		|| defined(__MOXIE_LITTLE_ENDIAN__) \
		|| defined(__PPC64LE__) \
		|| defined(__RX_LITTLE_ENDIAN__) \
		|| defined(__THUMBEL__) \
		|| defined(__little_endian__) \
		|| defined(__nios2_little_endian__) \
		|| defined(__ppc64le__) \
		|| XTE_ARCH_ALPHA \
		|| XTE_ARCH_ATMEL_AVR \
		|| XTE_ARCH_BLACKFIN \
		|| XTE_ARCH_COMPACTRISC \
		|| XTE_ARCH_ELBRUS_2000 \
		|| XTE_ARCH_FT32 \
		|| XTE_ARCH_H8300 \
		|| XTE_ARCH_I960 \
		|| XTE_ARCH_LOONGARCH \
		|| XTE_ARCH_M32C \
		|| XTE_ARCH_MN10200 \
		|| XTE_ARCH_MN10300 \
		|| XTE_ARCH_MSP430 \
		|| XTE_ARCH_RISC_V \
		|| XTE_ARCH_RL78 \
		|| XTE_ARCH_TIC_80 \
		|| XTE_ARCH_V850 \
		|| XTE_ARCH_WASM \
		|| XTE_ARCH_WDC_65C02 \
		|| XTE_ARCH_X86_32 \
		|| XTE_ARCH_X86_64 \
		|| XTE_ARCH_XSTORMY16 \
		|| XTE_ARCH_XTENSA \
		|| XTE_PLATFORM_CYGWIN \
		|| XTE_PLATFORM_WINDOWS
#		undef XTE_ENDIAN_LITTLE
#		define XTE_ENDIAN_LITTLE 1
#	endif
#
#	if defined(__BYTE_ORDER) && (__BYTE_ORDER == __PDP_ENDIAN)
#		undef XTE_ENDIAN_LITTLE_WORD
#		define XTE_ENDIAN_LITTLE_WORD 1
#	endif
#endif

// https://github.com/cpredef/predef/blob/master/Endianness.md
// https://github.com/isar/libmdbx/blob/9fa76a56fcb548f539094d2168e5cb3406d4e7e1/src/preface.h#L520-L541
