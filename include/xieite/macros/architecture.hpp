#ifndef XIEITE_HEADER_MACROS_ARCHITECTURE
#	define XIEITE_HEADER_MACROS_ARCHITECTURE

#	define XIEITE_ARCHITECTURE_AARCH64 0
#	define XIEITE_ARCHITECTURE_ALPHA 0
#	define XIEITE_ARCHITECTURE_ARM 0
#	define XIEITE_ARCHITECTURE_BLACKFIN 0
#	define XIEITE_ARCHITECTURE_CONVEX 0
#	define XIEITE_ARCHITECTURE_EPIPHANY 0
#	define XIEITE_ARCHITECTURE_ITANIUM 0
#	define XIEITE_ARCHITECTURE_MIPS 0
#	define XIEITE_ARCHITECTURE_MOTOROLA_86000 0
#	define XIEITE_ARCHITECTURE_PA_RISC 0
#	define XIEITE_ARCHITECTURE_POWERPC 0
#	define XIEITE_ARCHITECTURE_PYRAMID_9810 0
#	define XIEITE_ARCHITECTURE_RS_6000 0
#	define XIEITE_ARCHITECTURE_SPARC 0
#	define XIEITE_ARCHITECTURE_SUPERH 0
#	define XIEITE_ARCHITECTURE_TMS320 0
#	define XIEITE_ARCHITECTURE_TMS470 0
#	define XIEITE_ARCHITECTURE_X86_32 0
#	define XIEITE_ARCHITECTURE_X86_64 0
#	define XIEITE_ARCHITECTURE_Z 0

#	ifdef __aarch64__
#		undef XIEITE_ARCHITECTURE_AARCH64
#		define XIEITE_ARCHITECTURE_AARCH64 1
#	endif

#	if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#		undef XIEITE_ARCHITECTURE_ALPHA
#		define XIEITE_ARCHITECTURE_ALPHA 1
#	endif

#	if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_ARMT) || defined(__arm)
#		undef XIEITE_ARCHITECTURE_ARM
#		define XIEITE_ARCHITECTURE_ARM 1
#	endif

#	if defined(__bfin) || defined(__BFIN__)
#		undef XIEITE_ARCHITECTURE_BLACKFIN
#		define XIEITE_ARCHITECTURE_BLACKFIN 1
#	endif

#	ifdef __convex__
#		undef XIEITE_ARCHITECTURE_CONVEX
#		define XIEITE_ARCHITECTURE_CONVEX 1
#	endif

#	ifdef __epiphany__
#		undef XIEITE_ARCHITECTURE_EPIPHANY
#		define XIEITE_ARCHITECTURE_EPIPHANY 1
#	endif

#	if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#		undef XIEITE_ARCHITECTURE_ITANIUM
#		define XIEITE_ARCHITECTURE_ITANIUM 1
#	endif

#	if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#		undef XIEITE_ARCHITECTURE_MIPS
#		define XIEITE_ARCHITECTURE_MIPS 1
#	endif

#	if defined(__m86k__) || defined(M86000) || defined(__MC68K__)
#		undef XIEITE_ARCHITECTURE_MOTOROLA_86000
#		define XIEITE_ARCHITECTURE_MOTOROLA_86000 1
#	endif

#	if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#		undef XIEITE_ARCHITECTURE_PA_RISC
#		define XIEITE_ARCHITECTURE_PA_RISC 1
#	endif

#	if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC) || defined(__ppc)
#		undef XIEITE_ARCHITECTURE_POWERPC
#		define XIEITE_ARCHITECTURE_POWERPC 1
#	endif

#	ifdef pyr
#		undef XIEITE_ARCHITECTURE_PYRAMID_9810
#		define XIEITE_ARCHITECTURE_PYRAMID_9810 1
#	endif

#	if defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR4)
#		undef XIEITE_ARCHITECTURE_RS_6000
#		define XIEITE_ARCHITECTURE_RS_6000 1
#	endif

#	if defined(__sparc__) || defined(__sparc)
#		undef XIEITE_ARCHITECTURE_SPARC
#		define XIEITE_ARCHITECTURE_SPARC 1
#	endif

#	ifdef __sh__
#		undef XIEITE_ARCHITECTURE_SUPERH
#		define XIEITE_ARCHITECTURE_SUPERH 1
#	endif

#	if defined(_TMS320C2XX) || defined(__TMS320C2000__) || defined(_TMS320C5X) || defined(__TMS320C55X__) || defined(_TMS320C6X) || defined(__TMS320C6X__)
#		undef XIEITE_ARCHITECTURE_TMS320
#		define XIEITE_ARCHITECTURE_TMS320 1
#	endif

#	ifdef __TMS470__
#		undef XIEITE_ARCHITECTURE_TMS470
#		define XIEITE_ARCHITECTURE_TMS470 1
#	endif

#	if defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#		undef XIEITE_ARCHITECTURE_X86_32
#		define XIEITE_ARCHITECTURE_X86_32 1
#	endif

#	if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64)
#		undef XIEITE_ARCHITECTURE_X86_64
#		define XIEITE_ARCHITECTURE_X86_64 1
#	endif

#	if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#		undef XIEITE_ARCHITECTURE_Z
#		define XIEITE_ARCHITECTURE_Z 1
#	endif

#endif
