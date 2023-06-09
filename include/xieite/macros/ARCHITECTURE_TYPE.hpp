#ifndef XIEITE_HEADER_MACROS_ARCHITECTURE_TYPE
#	define XIEITE_HEADER_MACROS_ARCHITECTURE_TYPE

#	define XIEITE_ARCHITECTURE_TYPE_AARCH64 false
#	ifdef __aarch64__
#		define XIEITE_ARCHITECTURE_TYPE_AARCH64 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_ALPHA false
#	if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
#		define XIEITE_ARCHITECTURE_TYPE_ALPHA true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_ARM false
#	if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) || defined(_ARMT) || defined(__arm)
#		define XIEITE_ARCHITECTURE_TYPE_ARM true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_BLACKFIN false
#	if defined(__bfin) || defined(__BFIN__)
#		define XIEITE_ARCHITECTURE_TYPE_BLACKFIN true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_CONVEX false
#	ifdef __convex__
#		define XIEITE_ARCHITECTURE_TYPE_CONVEX true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_EPIPHANY false
#	ifdef __epiphany__
#		define XIEITE_ARCHITECTURE_TYPE_EPIPHANY true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_ITANIUM false
#	if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
#		define XIEITE_ARCHITECTURE_TYPE_ITANIUM true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_MIPS false
#	if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__)
#		define XIEITE_ARCHITECTURE_TYPE_MIPS true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_MOTOROLA_86000 false
#	if defined(__m86k__) || defined(M86000) || defined(__MC68K__)
#		define XIEITE_ARCHITECTURE_TYPE_MOTOROLA_86000 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_PA_RISC false
#	if defined(__hppa__) || defined(__HPPA__) || defined(__hppa)
#		define XIEITE_ARCHITECTURE_TYPE_PA_RISC true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_POWERPC false
#	if defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__ppc64__) || defined(__PPC__) || defined(__PPC64__) || defined(_ARCH_PPC) || defined(_ARCH_PPC64) || defined(_M_PPC) || defined(__ppc)
#		define XIEITE_ARCHITECTURE_TYPE_POWERPC true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_PYRAMID_9810 false
#	ifdef pyr
#		define XIEITE_ARCHITECTURE_TYPE_PYRAMID_9810 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_RS_6000 false
#	if defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2) || defined(_ARCH_PWR3) || defined(_ARCH_PWR4)
#		define XIEITE_ARCHITECTURE_TYPE_RS_6000 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_SPARC false
#	if defined(__sparc__) || defined(__sparc)
#		define XIEITE_ARCHITECTURE_TYPE_SPARC true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_SUPERH false
#	ifdef __sh__
#		define XIEITE_ARCHITECTURE_TYPE_SUPERH true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_TMS320 false
#	if defined(_TMS320C2XX) || defined(__TMS320C2000__) || defined(_TMS320C5X) || defined(__TMS320C55X__) || defined(_TMS320C6X) || defined(__TMS320C6X__)
#		define XIEITE_ARCHITECTURE_TYPE_TMS320 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_TMS470 false
#	ifdef __TMS470__
#		define XIEITE_ARCHITECTURE_TYPE_TMS470 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_X86_32 false
#	if defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
#		define XIEITE_ARCHITECTURE_TYPE_X86_32 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_X86_64 false
#	if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64)
#		define XIEITE_ARCHITECTURE_TYPE_X86_64 true
#	endif

#	define XIEITE_ARCHITECTURE_TYPE_Z false
#	if defined(__370__) || defined(__THW_370__) || defined(__s390__) || defined(__s390x__) || defined(__zarch__) || defined(__SYSC_ZARCH__)
#		define XIEITE_ARCHITECTURE_TYPE_Z true
#	endif

#endif
