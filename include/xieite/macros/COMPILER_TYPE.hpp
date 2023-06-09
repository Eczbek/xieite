#ifndef XIEITE_HEADER_MACROS_COMPILER_TYPE
#	define XIEITE_HEADER_MACROS_COMPILER_TYPE

#	define XIEITE_COMPILER_TYPE_ACC false
#	ifdef _ACC_
#		define XIEITE_COMPILER_TYPE_ACC true
#	endif

#	define XIEITE_COMPILER_TYPE_ACPP false
#	ifdef __HP_aCC
#		define XIEITE_COMPILER_TYPE_ACPP true
#	endif

#	define XIEITE_COMPILER_TYPE_AMSTERDAM_COMPILER_KIT false
#	ifdef __ACK__
#		define XIEITE_COMPILER_TYPE_AMSTERDAM_COMPILER_KIT true
#	endif

#	define XIEITE_COMPILER_TYPE_ANSI false
#	ifdef __HP_cc
#		define XIEITE_COMPILER_TYPE_ANSI true
#	endif

#	define XIEITE_COMPILER_TYPE_ARM false
#	ifdef __CC_ARM
#		define XIEITE_COMPILER_TYPE_ARM true
#	endif

#	define XIEITE_COMPILER_TYPE_AZTEC false
#	if defined(AZTEC_C) || defined(__AZTEC_C__)
#		define XIEITE_COMPILER_TYPE_AZTEC true
#	endif

#	define XIEITE_COMPILER_TYPE_BORLAND false
#	if defined(__BORLANDC__) || defined(__CODEGEARC__)
#		define XIEITE_COMPILER_TYPE_BORLAND true
#	endif

#	define XIEITE_COMPILER_TYPE_C166 false
#	ifdef __C166__
#		define XIEITE_COMPILER_TYPE_C166 true
#	endif

#	define XIEITE_COMPILER_TYPE_C51 false
#	if defined(__C51__) || defined(__CX51__)
#		define XIEITE_COMPILER_TYPE_C51 true
#	endif

#	define XIEITE_COMPILER_TYPE_CARM false
#	if defined(__CA__) || defined(__KEIL__)
#		define XIEITE_COMPILER_TYPE_CARM true
#	endif

#	define XIEITE_COMPILER_TYPE_CC65 false
#	ifdef __CC65__
#		define XIEITE_COMPILER_TYPE_CC65 true
#	endif

#	define XIEITE_COMPILER_TYPE_CLANG false
#	ifdef __clang__
#		define XIEITE_COMPILER_TYPE_CLANG true
#	endif

#	define XIEITE_COMPILER_TYPE_CODEWARRIOR false
#	if defined(__MWERKS__) || defined(__CWCC__)
#		define XIEITE_COMPILER_TYPE_CODEWARRIOR true
#	endif

#	define XIEITE_COMPILER_TYPE_COMEAU false
#	ifdef __COMO__
#		define XIEITE_COMPILER_TYPE_COMEAU true
#	endif

#	define XIEITE_COMPILER_TYPE_COMPAQ_C false
#	ifdef __DECC
#		define XIEITE_COMPILER_TYPE_COMPAQ_C true
#	endif

#	define XIEITE_COMPILER_TYPE_COMPAQ_CPP false
#	ifdef __DECCXX
#		define XIEITE_COMPILER_TYPE_COMPAQ_CPP true
#	endif

#	define XIEITE_COMPILER_TYPE_COMPCERT false
#	ifdef __COMPCERT__
#		define XIEITE_COMPILER_TYPE_COMPCERT true
#	endif

#	define XIEITE_COMPILER_TYPE_CONVEX false
#	ifdef __convexc__
#		define XIEITE_COMPILER_TYPE_CONVEX true
#	endif

#	define XIEITE_COMPILER_TYPE_COVERITY false
#	ifdef __COVERITY__
#		define XIEITE_COMPILER_TYPE_COVERITY true
#	endif

#	define XIEITE_COMPILER_TYPE_CRAY false
#	ifdef _CRAYC
#		define XIEITE_COMPILER_TYPE_CRAY true
#	endif

#	define XIEITE_COMPILER_TYPE_C_TO_HARDWARE false
#	ifdef __CHC__
#		define XIEITE_COMPILER_TYPE_C_TO_HARDWARE true
#	endif

#	define XIEITE_COMPILER_TYPE_DIAB false
#	ifdef __DCC__
#		define XIEITE_COMPILER_TYPE_DIAB true
#	endif

#	define XIEITE_COMPILER_TYPE_DICE false
#	ifdef _DICE
#		define XIEITE_COMPILER_TYPE_DICE true
#	endif

#	define XIEITE_COMPILER_TYPE_DIGITAL_MARS false
#	ifdef __DMC__
#		define XIEITE_COMPILER_TYPE_DIGITAL_MARS true
#	endif

#	define XIEITE_COMPILER_TYPE_DIGNUS false
#	ifdef __SYSC__
#		define XIEITE_COMPILER_TYPE_DIGNUS true
#	endif

#	define XIEITE_COMPILER_TYPE_DJGPP false
#	if defined(__DJGPP__) || defined(__GO32__)
#		define XIEITE_COMPILER_TYPE_DJGPP true
#	endif

#	define XIEITE_COMPILER_TYPE_EDG false
#	ifdef __EDG__
#		define XIEITE_COMPILER_TYPE_EDG true
#	endif

#	define XIEITE_COMPILER_TYPE_EKOPATH false
#	ifdef __PATHCC__
#		define XIEITE_COMPILER_TYPE_EKOPATH true
#	endif

#	define XIEITE_COMPILER_TYPE_FUJITSU false
#	ifdef __FCC_VERSION
#		define XIEITE_COMPILER_TYPE_FUJITSU true
#	endif

#	define XIEITE_COMPILER_TYPE_GCC false
#	ifdef __GNUC__
#		define XIEITE_COMPILER_TYPE_GCC true
#	endif

#	define XIEITE_COMPILER_TYPE_GREEN_HILLS false
#	ifdef __ghs__
#		define XIEITE_COMPILER_TYPE_GREEN_HILLS true
#	endif

#	define XIEITE_COMPILER_TYPE_HIGH false
#	ifdef __HIGHC__
#		define XIEITE_COMPILER_TYPE_HIGH true
#	endif

#	define XIEITE_COMPILER_TYPE_IAR false
#	ifdef __IAR_SYSTEMS_ICC__
#		define XIEITE_COMPILER_TYPE_IAR true
#	endif

#	define XIEITE_COMPILER_TYPE_IMAGECRAFT false
#	ifdef __IMAGECRAFT__
#		define XIEITE_COMPILER_TYPE_IMAGECRAFT true
#	endif

#	define XIEITE_COMPILER_TYPE_INTEL false
#	if defined(__INTEL_COMPILER) || defined(__ICL)
#		define XIEITE_COMPILER_TYPE_INTEL true
#	endif

#	define XIEITE_COMPILER_TYPE_KAI false
#	ifdef __KCC
#		define XIEITE_COMPILER_TYPE_KAI true
#	endif

#	define XIEITE_COMPILER_TYPE_LCC false
#	ifdef __LCC__
#		define XIEITE_COMPILER_TYPE_LCC true
#	endif

#	define XIEITE_COMPILER_TYPE_LLVM false
#	ifdef __llvm__
#		define XIEITE_COMPILER_TYPE_LLVM true
#	endif

#	define XIEITE_COMPILER_TYPE_MACINTOSH_PROGRAMMERS_WORKSHOP false
#	if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#		define XIEITE_COMPILER_TYPE_MACINTOSH_PROGRAMMERS_WORKSHOP true
#	endif

#	define XIEITE_COMPILER_TYPE_MICROBLAZE false
#	ifdef __CMB__
#		define XIEITE_COMPILER_TYPE_MICROBLAZE true
#	endif

#	define XIEITE_COMPILER_TYPE_MICROTEC false
#	ifdef _MRI
#		define XIEITE_COMPILER_TYPE_MICROTEC true
#	endif

#	define XIEITE_COMPILER_TYPE_MIPSPRO false
#	if defined(__sgi) || defined(sgi)
#		define XIEITE_COMPILER_TYPE_MIPSPRO true
#	endif

#	define XIEITE_COMPILER_TYPE_MIRACLE false
#	ifdef MIRACLE
#		define XIEITE_COMPILER_TYPE_MIRACLE true
#	endif

#	define XIEITE_COMPILER_TYPE_MSVC false
#	ifdef _MSC_VER
#		define XIEITE_COMPILER_TYPE_MSVC true
#	endif

#	define XIEITE_COMPILER_TYPE_NDP false
#	if defined(__NDPC__) || defined(__NDPX__)
#		define XIEITE_COMPILER_TYPE_NDP true
#	endif

#	define XIEITE_COMPILER_TYPE_NORCROFT false
#	ifdef __CC_NORCROFT
#		define XIEITE_COMPILER_TYPE_NORCROFT true
#	endif

#	define XIEITE_COMPILER_TYPE_NWCC false
#	ifdef __NWCC__
#		define XIEITE_COMPILER_TYPE_NWCC true
#	endif

#	define XIEITE_COMPILER_TYPE_OPEN64 false
#	if defined(__OPEN64__) || defined(__OPENCC__)
#		define XIEITE_COMPILER_TYPE_OPEN64 true
#	endif

#	define XIEITE_COMPILER_TYPE_OPENSERVER false
#	ifdef _SCO_DS
#		define XIEITE_COMPILER_TYPE_OPENSERVER true
#	endif

#	define XIEITE_COMPILER_TYPE_PACIFIC false
#	ifdef __PACIFIC__
#		define XIEITE_COMPILER_TYPE_PACIFIC true
#	endif

#	define XIEITE_COMPILER_TYPE_PALM false
#	ifdef _PACC_VER
#		define XIEITE_COMPILER_TYPE_PALM true
#	endif

#	define XIEITE_COMPILER_TYPE_PELLES false
#	ifdef __POCC__
#		define XIEITE_COMPILER_TYPE_PELLES true
#	endif

#	define XIEITE_COMPILER_TYPE_PORTLAND_GROUP false
#	ifdef __PGI
#		define XIEITE_COMPILER_TYPE_PORTLAND_GROUP true
#	endif

#	define XIEITE_COMPILER_TYPE_PRO false
#	ifdef ORA_PROC
#		define XIEITE_COMPILER_TYPE_PRO true
#	endif

#	define XIEITE_COMPILER_TYPE_RENESAS false
#	if defined(__RENESAS__) || defined(__HITACHI__)
#		define XIEITE_COMPILER_TYPE_RENESAS true
#	endif

#	define XIEITE_COMPILER_TYPE_SAS false
#	if defined(SASC) || defined(__SASC) || defined(__SASC__)
#		define XIEITE_COMPILER_TYPE_SAS true
#	endif

#	define XIEITE_COMPILER_TYPE_SMALL_DEVICE false
#	ifdef SDCC
#		define XIEITE_COMPILER_TYPE_SMALL_DEVICE true
#	endif

#	define XIEITE_COMPILER_TYPE_SN false
#	ifdef __SNC__
#		define XIEITE_COMPILER_TYPE_SN true
#	endif

#	define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_C false
#	ifdef __SUNPRO_C
#		define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_C true
#	endif

#	define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_CPP false
#	ifdef __SUNPRO_CC
#		define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_CPP true
#	endif

#	define XIEITE_COMPILER_TYPE_SYMANTEC false
#	ifdef __SC__
#		define XIEITE_COMPILER_TYPE_SYMANTEC true
#	endif

#	define XIEITE_COMPILER_TYPE_TENDRA false
#	ifdef __TenDRA__
#		define XIEITE_COMPILER_TYPE_TENDRA true
#	endif

#	define XIEITE_COMPILER_TYPE_THINK false
#	if defined(THINKC3) || defined(THINKC4)
#		define XIEITE_COMPILER_TYPE_THINK true
#	endif

#	define XIEITE_COMPILER_TYPE_TINY false
#	ifdef __TINYC__
#		define XIEITE_COMPILER_TYPE_TINY true
#	endif

#	define XIEITE_COMPILER_TYPE_TMS320 false
#	if defined(__TI_COMPILER_VERION__) || defined(_TMS320C6X)
#		define XIEITE_COMPILER_TYPE_TMS320 true
#	endif

#	define XIEITE_COMPILER_TYPE_TURBO false
#	ifdef __TURBOC__
#		define XIEITE_COMPILER_TYPE_TURBO true
#	endif

#	define XIEITE_COMPILER_TYPE_ULTIMATE false
#	ifdef _UCC
#		define XIEITE_COMPILER_TYPE_ULTIMATE true
#	endif

#	define XIEITE_COMPILER_TYPE_USL false
#	ifdef __USLC__
#		define XIEITE_COMPILER_TYPE_USL true
#	endif

#	define XIEITE_COMPILER_TYPE_VBCC false
#	ifdef __VBCC__
#		define XIEITE_COMPILER_TYPE_VBCC true
#	endif

#	define XIEITE_COMPILER_TYPE_VOS false
#	ifdef __VOSC__
#		define XIEITE_COMPILER_TYPE_VOS true
#	endif

#	define XIEITE_COMPILER_TYPE_WATCOM false
#	ifdef __WATCOMC__
#		define XIEITE_COMPILER_TYPE_WATCOM true
#	endif

#	define XIEITE_COMPILER_TYPE_WINGW32 false
#	ifdef __MINGW32__
#		define XIEITE_COMPILER_TYPE_WINGW32 true
#	endif

#	define XIEITE_COMPILER_TYPE_WINGW64 false
#	ifdef __MINGW64__
#		define XIEITE_COMPILER_TYPE_WINGW64 true
#	endif

#	define XIEITE_COMPILER_TYPE_XL_CLANG false
#	ifdef __ibmxl__
#		define XIEITE_COMPILER_TYPE_XL_CLANG true
#	endif

#	define XIEITE_COMPILER_TYPE_XL_LEGACY false
#	ifdef __xlC__
#		define XIEITE_COMPILER_TYPE_XL_LEGACY true
#	endif

#	define XIEITE_COMPILER_TYPE_ZORTECH false
#	ifdef __ZTC__
#		define XIEITE_COMPILER_TYPE_ZORTECH true
#	endif

#	define XIEITE_COMPILER_TYPE_Z_OS_XL_C false
#	ifdef __IBMC__
#		define XIEITE_COMPILER_TYPE_Z_OS_XL_C true
#	endif

#	define XIEITE_COMPILER_TYPE_Z_OS_XL_CPP false
#	ifdef __IBMCPP__
#		define XIEITE_COMPILER_TYPE_Z_OS_XL_CPP true
#	endif

#endif
