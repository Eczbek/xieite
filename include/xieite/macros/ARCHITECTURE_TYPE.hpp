#ifndef XIEITE_HEADER__MACROS__ARCHITECTURE_TYPE
#	define XIEITE_HEADER__MACROS__ARCHITECTURE_TYPE

#	define XIEITE__ARCHITECTURE_TYPE__AARCH64 false
#	define XIEITE__ARCHITECTURE_TYPE__ALPHA false
#	define XIEITE__ARCHITECTURE_TYPE__ARM false
#	define XIEITE__ARCHITECTURE_TYPE__BLACKFIN false
#	define XIEITE__ARCHITECTURE_TYPE__CONVEX false
#	define XIEITE__ARCHITECTURE_TYPE__EPIPHANY false
#	define XIEITE__ARCHITECTURE_TYPE__ITANIUM false
#	define XIEITE__ARCHITECTURE_TYPE__MIPS false
#	define XIEITE__ARCHITECTURE_TYPE__MOTOROLA_86000 false
#	define XIEITE__ARCHITECTURE_TYPE__PA_RISC false
#	define XIEITE__ARCHITECTURE_TYPE__POWERPC false
#	define XIEITE__ARCHITECTURE_TYPE__PYRAMID_9810 false
#	define XIEITE__ARCHITECTURE_TYPE__RS_6000 false
#	define XIEITE__ARCHITECTURE_TYPE__SPARC false
#	define XIEITE__ARCHITECTURE_TYPE__SUPERH false
#	define XIEITE__ARCHITECTURE_TYPE__TMS320 false
#	define XIEITE__ARCHITECTURE_TYPE__TMS470 false
#	define XIEITE__ARCHITECTURE_TYPE__X86_32 false
#	define XIEITE__ARCHITECTURE_TYPE__X86_64 false
#	define XIEITE__ARCHITECTURE_TYPE__Z false

#	ifdef __aarch64__
#		undef XIEITE__ARCHITECTURE_TYPE__AARCH64
#		define XIEITE__ARCHITECTURE_TYPE__AARCH64 true
#	endif

#	if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#		undef XIEITE__ARCHITECTURE_TYPE__ALPHA
#		define XIEITE__ARCHITECTURE_TYPE__ALPHA true
#	endif

#	if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_ARMT) || defined(__arm)
#		undef XIEITE__ARCHITECTURE_TYPE__ARM
#		define XIEITE__ARCHITECTURE_TYPE__ARM true
#	endif

#	if defined(__bfin) || defined(__BFIN__)
#		undef XIEITE__ARCHITECTURE_TYPE__BLACKFIN
#		define XIEITE__ARCHITECTURE_TYPE__BLACKFIN true
#	endif

#	ifdef __convex__
#		undef XIEITE__ARCHITECTURE_TYPE__CONVEX
#		define XIEITE__ARCHITECTURE_TYPE__CONVEX true
#	endif

#	ifdef __epiphany__
#		undef XIEITE__ARCHITECTURE_TYPE__EPIPHANY
#		define XIEITE__ARCHITECTURE_TYPE__EPIPHANY true
#	endif

#	if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#		undef XIEITE__ARCHITECTURE_TYPE__ITANIUM
#		define XIEITE__ARCHITECTURE_TYPE__ITANIUM true
#	endif

#	if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#		undef XIEITE__ARCHITECTURE_TYPE__MIPS
#		define XIEITE__ARCHITECTURE_TYPE__MIPS true
#	endif

#	if defined(__m86k__) || defined(M86000) || defined(__MC68K__)
#		undef XIEITE__ARCHITECTURE_TYPE__MOTOROLA_86000
#		define XIEITE__ARCHITECTURE_TYPE__MOTOROLA_86000 true
#	endif

#	if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#		undef XIEITE__ARCHITECTURE_TYPE__PA_RISC
#		define XIEITE__ARCHITECTURE_TYPE__PA_RISC true
#	endif

#	if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC) || defined(__ppc)
#		undef XIEITE__ARCHITECTURE_TYPE__POWERPC
#		define XIEITE__ARCHITECTURE_TYPE__POWERPC true
#	endif

#	ifdef pyr
#		undef XIEITE__ARCHITECTURE_TYPE__PYRAMID_9810
#		define XIEITE__ARCHITECTURE_TYPE__PYRAMID_9810 true
#	endif

#	if defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR4)
#		undef XIEITE__ARCHITECTURE_TYPE__RS_6000
#		define XIEITE__ARCHITECTURE_TYPE__RS_6000 true
#	endif

#	if defined(__sparc__) || defined(__sparc)
#		undef XIEITE__ARCHITECTURE_TYPE__SPARC
#		define XIEITE__ARCHITECTURE_TYPE__SPARC true
#	endif

#	ifdef __sh__
#		undef XIEITE__ARCHITECTURE_TYPE__SUPERH
#		define XIEITE__ARCHITECTURE_TYPE__SUPERH true
#	endif

#	if defined(_TMS320C2XX) || defined(__TMS320C2000__) || defined(_TMS320C5X) || defined(__TMS320C55X__) || defined(_TMS320C6X) || defined(__TMS320C6X__)
#		undef XIEITE__ARCHITECTURE_TYPE__TMS320
#		define XIEITE__ARCHITECTURE_TYPE__TMS320 true
#	endif

#	ifdef __TMS470__
#		undef XIEITE__ARCHITECTURE_TYPE__TMS470
#		define XIEITE__ARCHITECTURE_TYPE__TMS470 true
#	endif

#	if defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#		undef XIEITE__ARCHITECTURE_TYPE__X86_32
#		define XIEITE__ARCHITECTURE_TYPE__X86_32 true
#	endif

#	if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64)
#		undef XIEITE__ARCHITECTURE_TYPE__X86_64
#		define XIEITE__ARCHITECTURE_TYPE__X86_64 true
#	endif

#	if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#		undef XIEITE__ARCHITECTURE_TYPE__Z
#		define XIEITE__ARCHITECTURE_TYPE__Z true
#	endif

#endif
