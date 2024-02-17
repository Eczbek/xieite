#ifndef XIEITE_HEADER_MACROS_ENDIANNESS
#	define XIEITE_HEADER_MACROS_ENDIANNESS

#	define XIEITE_ENDIANNESS_BIG 0
#	define XIEITE_ENDIANNESS_LITTLE 0
#	define XIEITE_ENDIANNESS_BIG_WORD 0
#	define XEIITE_ENDIANNESS_LITTLE_WORD 0

#	if __has_include(<endian.h>)
#		include <endian.h>
#	endif

#	if __has_include(<sys/param.h>)
#		include <sys/param.h>
#	endif

#	if defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN) || defined(__BIG_ENDIAN__) || defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__) || defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) || defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__)
#		undef XIEITE_ENDIANNESS_BIG
#		define XIEITE_ENDIANNESS_BIG 1
#	endif

#	if defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__) || defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__) || defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) || defined(__FLOAT_WORD_ORDER__) && (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#		undef XIEITE_ENDIANNESS_LITTLE
#		define XIEITE_ENDIANNESS_LITTLE 1
#	endif

#	if defined(__BYTE_ORDER) && (__BYTE_ORDER == __PDP_ENDIAN)
#		undef XIEITE_ENDIANNESS_LITTLE_WORD
#		define XIEITE_ENDIANNESS_LITTLE_WORD 1
#	endif

#endif

// https://sourceforge.net/p/predef/wiki/Endianness/
