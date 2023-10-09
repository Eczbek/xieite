#ifndef XIEITE_HEADER__MACROS__COMPILER_TYPE
#	define XIEITE_HEADER__MACROS__COMPILER_TYPE

#	define XIEITE__COMPILER_TYPE__ACC false
#	define XIEITE__COMPILER_TYPE__ACPP false
#	define XIEITE__COMPILER_TYPE__AMSTERDAM_COMPILER_KIT false
#	define XIEITE__COMPILER_TYPE__ANSI false
#	define XIEITE__COMPILER_TYPE__ARM false
#	define XIEITE__COMPILER_TYPE__AZTEC false
#	define XIEITE__COMPILER_TYPE__BORLAND false
#	define XIEITE__COMPILER_TYPE__C166 false
#	define XIEITE__COMPILER_TYPE__C51 false
#	define XIEITE__COMPILER_TYPE__CARM false
#	define XIEITE__COMPILER_TYPE__CC65 false
#	define XIEITE__COMPILER_TYPE__CLANG false
#	define XIEITE__COMPILER_TYPE__CODEWARRIOR false
#	define XIEITE__COMPILER_TYPE__COMEAU false
#	define XIEITE__COMPILER_TYPE__COMPAQ_C false
#	define XIEITE__COMPILER_TYPE__COMPAQ_CPP false
#	define XIEITE__COMPILER_TYPE__COMPCERT false
#	define XIEITE__COMPILER_TYPE__CONVEX false
#	define XIEITE__COMPILER_TYPE__COVERITY false
#	define XIEITE__COMPILER_TYPE__CRAY false
#	define XIEITE__COMPILER_TYPE__C_TO_HARDWARE false
#	define XIEITE__COMPILER_TYPE__DIAB false
#	define XIEITE__COMPILER_TYPE__DICE false
#	define XIEITE__COMPILER_TYPE__DIGITAL_MARS false
#	define XIEITE__COMPILER_TYPE__DIGNUS false
#	define XIEITE__COMPILER_TYPE__DJGPP false
#	define XIEITE__COMPILER_TYPE__EDG false
#	define XIEITE__COMPILER_TYPE__EKOPATH false
#	define XIEITE__COMPILER_TYPE__FUJITSU false
#	define XIEITE__COMPILER_TYPE__GCC false
#	define XIEITE__COMPILER_TYPE__GREEN_HILLS false
#	define XIEITE__COMPILER_TYPE__HIGH false
#	define XIEITE__COMPILER_TYPE__IAR false
#	define XIEITE__COMPILER_TYPE__IMAGECRAFT false
#	define XIEITE__COMPILER_TYPE__INTEL false
#	define XIEITE__COMPILER_TYPE__KAI false
#	define XIEITE__COMPILER_TYPE__LCC false
#	define XIEITE__COMPILER_TYPE__LLVM false
#	define XIEITE__COMPILER_TYPE__MACINTOSH_PROGRAMMERS_WORKSHOP false
#	define XIEITE__COMPILER_TYPE__MICROBLAZE false
#	define XIEITE__COMPILER_TYPE__MICROTEC false
#	define XIEITE__COMPILER_TYPE__MIPSPRO false
#	define XIEITE__COMPILER_TYPE__MIRACLE false
#	define XIEITE__COMPILER_TYPE__MSVC false
#	define XIEITE__COMPILER_TYPE__NDP false
#	define XIEITE__COMPILER_TYPE__NORCROFT false
#	define XIEITE__COMPILER_TYPE__NWCC false
#	define XIEITE__COMPILER_TYPE__OPEN64 false
#	define XIEITE__COMPILER_TYPE__OPENSERVER false
#	define XIEITE__COMPILER_TYPE__PACIFIC false
#	define XIEITE__COMPILER_TYPE__PALM false
#	define XIEITE__COMPILER_TYPE__PELLES false
#	define XIEITE__COMPILER_TYPE__PORTLAND_GROUP false
#	define XIEITE__COMPILER_TYPE__PRO false
#	define XIEITE__COMPILER_TYPE__RENESAS false
#	define XIEITE__COMPILER_TYPE__SAS false
#	define XIEITE__COMPILER_TYPE__SMALL_DEVICE false
#	define XIEITE__COMPILER_TYPE__SN false
#	define XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_C false
#	define XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_CPP false
#	define XIEITE__COMPILER_TYPE__SYMANTEC false
#	define XIEITE__COMPILER_TYPE__TENDRA false
#	define XIEITE__COMPILER_TYPE__THINK false
#	define XIEITE__COMPILER_TYPE__TINY false
#	define XIEITE__COMPILER_TYPE__TMS320 false
#	define XIEITE__COMPILER_TYPE__TURBO false
#	define XIEITE__COMPILER_TYPE__ULTIMATE false
#	define XIEITE__COMPILER_TYPE__USL false
#	define XIEITE__COMPILER_TYPE__VBCC false
#	define XIEITE__COMPILER_TYPE__VOS false
#	define XIEITE__COMPILER_TYPE__WATCOM false
#	define XIEITE__COMPILER_TYPE__WINGW32 false
#	define XIEITE__COMPILER_TYPE__WINGW64 false
#	define XIEITE__COMPILER_TYPE__XL_CLANG false
#	define XIEITE__COMPILER_TYPE__XL_LEGACY false
#	define XIEITE__COMPILER_TYPE__ZORTECH false
#	define XIEITE__COMPILER_TYPE__Z_OS_XL_C false
#	define XIEITE__COMPILER_TYPE__Z_OS_XL_CPP false

#	ifdef _ACC_
#		undef XIEITE__COMPILER_TYPE__ACC
#		define XIEITE__COMPILER_TYPE__ACC true
#	endif

#	ifdef __HP_aCC
#		undef XIEITE__COMPILER_TYPE__ACPP
#		define XIEITE__COMPILER_TYPE__ACPP true
#	endif

#	ifdef __ACK__
#		undef XIEITE__COMPILER_TYPE__AMSTERDAM_COMPILER_KIT
#		define XIEITE__COMPILER_TYPE__AMSTERDAM_COMPILER_KIT true
#	endif

#	ifdef __HP_cc
#		undef XIEITE__COMPILER_TYPE__ANSI
#		define XIEITE__COMPILER_TYPE__ANSI true
#	endif

#	ifdef __CC_ARM
#		undef XIEITE__COMPILER_TYPE__ARM
#		define XIEITE__COMPILER_TYPE__ARM true
#	endif

#	if defined(AZTEC_C) || defined(__AZTEC_C__)
#		undef XIEITE__COMPILER_TYPE__AZTEC
#		define XIEITE__COMPILER_TYPE__AZTEC true
#	endif

#	if defined(__BORLANDC__) || defined(__CODEGEARC__)
#		undef XIEITE__COMPILER_TYPE__BORLAND
#		define XIEITE__COMPILER_TYPE__BORLAND true
#	endif

#	ifdef __C166__
#		undef XIEITE__COMPILER_TYPE__C166
#		define XIEITE__COMPILER_TYPE__C166 true
#	endif

#	if defined(__C51__) || defined(__CX51__)
#		undef XIEITE__COMPILER_TYPE__C51
#		define XIEITE__COMPILER_TYPE__C51 true
#	endif

#	if defined(__CA__) || defined(__KEIL__)
#		undef XIEITE__COMPILER_TYPE__CARM
#		define XIEITE__COMPILER_TYPE__CARM true
#	endif

#	ifdef __CC65__
#		undef XIEITE__COMPILER_TYPE__CC65
#		define XIEITE__COMPILER_TYPE__CC65 true
#	endif

#	ifdef __clang__
#		undef XIEITE__COMPILER_TYPE__CLANG
#		define XIEITE__COMPILER_TYPE__CLANG true
#	endif

#	if defined(__MWERKS__) || defined(__CWCC__)
#		undef XIEITE__COMPILER_TYPE__CODEWARRIOR
#		define XIEITE__COMPILER_TYPE__CODEWARRIOR true
#	endif

#	ifdef __COMO__
#		undef XIEITE__COMPILER_TYPE__COMEAU
#		define XIEITE__COMPILER_TYPE__COMEAU true
#	endif

#	ifdef __DECC
#		undef XIEITE__COMPILER_TYPE__COMPAQ_C
#		define XIEITE__COMPILER_TYPE__COMPAQ_C true
#	endif

#	ifdef __DECCXX
#		undef XIEITE__COMPILER_TYPE__COMPAQ_CPP
#		define XIEITE__COMPILER_TYPE__COMPAQ_CPP true
#	endif

#	ifdef __COMPCERT__
#		undef XIEITE__COMPILER_TYPE__COMPCERT
#		define XIEITE__COMPILER_TYPE__COMPCERT true
#	endif

#	ifdef __convexc__
#		undef XIEITE__COMPILER_TYPE__CONVEX
#		define XIEITE__COMPILER_TYPE__CONVEX true
#	endif

#	ifdef __COVERITY__
#		undef XIEITE__COMPILER_TYPE__COVERITY
#		define XIEITE__COMPILER_TYPE__COVERITY true
#	endif

#	ifdef _CRAYC
#		undef XIEITE__COMPILER_TYPE__CRAY
#		define XIEITE__COMPILER_TYPE__CRAY true
#	endif

#	ifdef __CHC__
#		undef XIEITE__COMPILER_TYPE__C_TO_HARDWARE
#		define XIEITE__COMPILER_TYPE__C_TO_HARDWARE true
#	endif

#	ifdef __DCC__
#		undef XIEITE__COMPILER_TYPE__DIAB
#		define XIEITE__COMPILER_TYPE__DIAB true
#	endif

#	ifdef _DICE
#		undef XIEITE__COMPILER_TYPE__DICE
#		define XIEITE__COMPILER_TYPE__DICE true
#	endif

#	ifdef __DMC__
#		undef XIEITE__COMPILER_TYPE__DIGITAL_MARS
#		define XIEITE__COMPILER_TYPE__DIGITAL_MARS true
#	endif

#	ifdef __SYSC__
#		undef XIEITE__COMPILER_TYPE__DIGNUS
#		define XIEITE__COMPILER_TYPE__DIGNUS true
#	endif

#	if defined(__DJGPP__) || defined(__GO32__)
#		undef XIEITE__COMPILER_TYPE__DJGPP
#		define XIEITE__COMPILER_TYPE__DJGPP true
#	endif

#	ifdef __EDG__
#		undef XIEITE__COMPILER_TYPE__EDG
#		define XIEITE__COMPILER_TYPE__EDG true
#	endif

#	ifdef __PATHCC__
#		undef XIEITE__COMPILER_TYPE__EKOPATH
#		define XIEITE__COMPILER_TYPE__EKOPATH true
#	endif

#	ifdef __FCC_VERSION
#		undef XIEITE__COMPILER_TYPE__FUJITSU
#		define XIEITE__COMPILER_TYPE__FUJITSU true
#	endif

#	ifdef __GNUC__
#		undef XIEITE__COMPILER_TYPE__GCC
#		define XIEITE__COMPILER_TYPE__GCC true
#	endif

#	ifdef __ghs__
#		undef XIEITE__COMPILER_TYPE__GREEN_HILLS
#		define XIEITE__COMPILER_TYPE__GREEN_HILLS true
#	endif

#	ifdef __HIGHC__
#		undef XIEITE__COMPILER_TYPE__HIGH
#		define XIEITE__COMPILER_TYPE__HIGH true
#	endif

#	ifdef __IAR_SYSTEMS_ICC__
#		undef XIEITE__COMPILER_TYPE__IAR
#		define XIEITE__COMPILER_TYPE__IAR true
#	endif

#	ifdef __IMAGECRAFT__
#		undef XIEITE__COMPILER_TYPE__IMAGECRAFT
#		define XIEITE__COMPILER_TYPE__IMAGECRAFT true
#	endif

#	if defined(__INTEL_COMPILER) || defined(__ICL)
#		undef XIEITE__COMPILER_TYPE__INTEL
#		define XIEITE__COMPILER_TYPE__INTEL true
#	endif

#	ifdef __KCC
#		undef XIEITE__COMPILER_TYPE__KAI
#		define XIEITE__COMPILER_TYPE__KAI true
#	endif

#	ifdef __LCC__
#		undef XIEITE__COMPILER_TYPE__LCC
#		define XIEITE__COMPILER_TYPE__LCC true
#	endif

#	ifdef __llvm__
#		undef XIEITE__COMPILER_TYPE__LLVM
#		define XIEITE__COMPILER_TYPE__LLVM true
#	endif

#	if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#		undef XIEITE__COMPILER_TYPE__MACINTOSH_PROGRAMMERS_WORKSHOP
#		define XIEITE__COMPILER_TYPE__MACINTOSH_PROGRAMMERS_WORKSHOP true
#	endif

#	ifdef __CMB__
#		undef XIEITE__COMPILER_TYPE__MICROBLAZE
#		define XIEITE__COMPILER_TYPE__MICROBLAZE true
#	endif

#	ifdef _MRI
#		undef XIEITE__COMPILER_TYPE__MICROTEC
#		define XIEITE__COMPILER_TYPE__MICROTEC true
#	endif

#	if defined(__sgi) || defined(sgi)
#		undef XIEITE__COMPILER_TYPE__MIPSPRO
#		define XIEITE__COMPILER_TYPE__MIPSPRO true
#	endif

#	ifdef MIRACLE
#		undef XIEITE__COMPILER_TYPE__MIRACLE
#		define XIEITE__COMPILER_TYPE__MIRACLE true
#	endif

#	ifdef _MSC_VER
#		undef XIEITE__COMPILER_TYPE__MSVC
#		define XIEITE__COMPILER_TYPE__MSVC true
#	endif

#	if defined(__NDPC__) || defined(__NDPX__)
#		undef XIEITE__COMPILER_TYPE__NDP
#		define XIEITE__COMPILER_TYPE__NDP true
#	endif

#	ifdef __CC_NORCROFT
#		undef XIEITE__COMPILER_TYPE__NORCROFT
#		define XIEITE__COMPILER_TYPE__NORCROFT true
#	endif

#	ifdef __NWCC__
#		undef XIEITE__COMPILER_TYPE__NWCC
#		define XIEITE__COMPILER_TYPE__NWCC true
#	endif

#	if defined(__OPEN64__) || defined(__OPENCC__)
#		undef XIEITE__COMPILER_TYPE__OPEN64
#		define XIEITE__COMPILER_TYPE__OPEN64 true
#	endif

#	ifdef _SCO_DS
#		undef XIEITE__COMPILER_TYPE__OPENSERVER
#		define XIEITE__COMPILER_TYPE__OPENSERVER true
#	endif

#	ifdef __PACIFIC__
#		undef XIEITE__COMPILER_TYPE__PACIFIC
#		define XIEITE__COMPILER_TYPE__PACIFIC true
#	endif

#	ifdef _PACC_VER
#		undef XIEITE__COMPILER_TYPE__PALM
#		define XIEITE__COMPILER_TYPE__PALM true
#	endif

#	ifdef __POCC__
#		undef XIEITE__COMPILER_TYPE__PELLES
#		define XIEITE__COMPILER_TYPE__PELLES true
#	endif

#	ifdef __PGI
#		undef XIEITE__COMPILER_TYPE__PORTLAND_GROUP
#		define XIEITE__COMPILER_TYPE__PORTLAND_GROUP true
#	endif

#	ifdef ORA_PROC
#		undef XIEITE__COMPILER_TYPE__PRO
#		define XIEITE__COMPILER_TYPE__PRO true
#	endif

#	if defined(__RENESAS__) || defined(__HITACHI__)
#		undef XIEITE__COMPILER_TYPE__RENESAS
#		define XIEITE__COMPILER_TYPE__RENESAS true
#	endif

#	if defined(SASC) || defined(__SASC) || defined(__SASC__)
#		undef XIEITE__COMPILER_TYPE__SAS
#		define XIEITE__COMPILER_TYPE__SAS true
#	endif

#	ifdef SDCC
#		undef XIEITE__COMPILER_TYPE__SMALL_DEVICE
#		define XIEITE__COMPILER_TYPE__SMALL_DEVICE true
#	endif

#	ifdef __SNC__
#		undef XIEITE__COMPILER_TYPE__SN
#		define XIEITE__COMPILER_TYPE__SN true
#	endif

#	ifdef __SUNPRO_C
#		undef XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_C
#		define XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_C true
#	endif

#	ifdef __SUNPRO_CC
#		undef XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_CPP
#		define XIEITE__COMPILER_TYPE__SOLARIS_STUDIO_CPP true
#	endif

#	ifdef __SC__
#		undef XIEITE__COMPILER_TYPE__SYMANTEC
#		define XIEITE__COMPILER_TYPE__SYMANTEC true
#	endif

#	ifdef __TenDRA__
#		undef XIEITE__COMPILER_TYPE__TENDRA
#		define XIEITE__COMPILER_TYPE__TENDRA true
#	endif

#	if defined(THINKC3) || defined(THINKC4)
#		undef XIEITE__COMPILER_TYPE__THINK
#		define XIEITE__COMPILER_TYPE__THINK true
#	endif

#	ifdef __TINYC__
#		undef XIEITE__COMPILER_TYPE__TINY
#		define XIEITE__COMPILER_TYPE__TINY true
#	endif

#	if defined(__TI_COMPILER_VERION__) || defined(_TMS320C6X)
#		undef XIEITE__COMPILER_TYPE__TMS320
#		define XIEITE__COMPILER_TYPE__TMS320 true
#	endif

#	ifdef __TURBOC__
#		undef XIEITE__COMPILER_TYPE__TURBO
#		define XIEITE__COMPILER_TYPE__TURBO true
#	endif

#	ifdef _UCC
#		undef XIEITE__COMPILER_TYPE__ULTIMATE
#		define XIEITE__COMPILER_TYPE__ULTIMATE true
#	endif

#	ifdef __USLC__
#		undef XIEITE__COMPILER_TYPE__USL
#		define XIEITE__COMPILER_TYPE__USL true
#	endif

#	ifdef __VBCC__
#		undef XIEITE__COMPILER_TYPE__VBCC
#		define XIEITE__COMPILER_TYPE__VBCC true
#	endif

#	ifdef __VOSC__
#		undef XIEITE__COMPILER_TYPE__VOS
#		define XIEITE__COMPILER_TYPE__VOS true
#	endif

#	ifdef __WATCOMC__
#		undef XIEITE__COMPILER_TYPE__WATCOM
#		define XIEITE__COMPILER_TYPE__WATCOM true
#	endif

#	ifdef __MINGW32__
#		undef XIEITE__COMPILER_TYPE__WINGW32
#		define XIEITE__COMPILER_TYPE__WINGW32 true
#	endif

#	ifdef __MINGW64__
#		undef XIEITE__COMPILER_TYPE__WINGW64
#		define XIEITE__COMPILER_TYPE__WINGW64 true
#	endif

#	ifdef __ibmxl__
#		undef XIEITE__COMPILER_TYPE__XL_CLANG
#		define XIEITE__COMPILER_TYPE__XL_CLANG true
#	endif

#	ifdef __xlC__
#		undef XIEITE__COMPILER_TYPE__XL_LEGACY
#		define XIEITE__COMPILER_TYPE__XL_LEGACY true
#	endif

#	ifdef __ZTC__
#		undef XIEITE__COMPILER_TYPE__ZORTECH
#		define XIEITE__COMPILER_TYPE__ZORTECH true
#	endif

#	ifdef __IBMC__
#		undef XIEITE__COMPILER_TYPE__Z_OS_XL_C
#		define XIEITE__COMPILER_TYPE__Z_OS_XL_C true
#	endif

#	ifdef __IBMCPP__
#		undef XIEITE__COMPILER_TYPE__Z_OS_XL_CPP
#		define XIEITE__COMPILER_TYPE__Z_OS_XL_CPP true
#	endif

#endif
