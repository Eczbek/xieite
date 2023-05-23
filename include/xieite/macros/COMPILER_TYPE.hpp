#ifndef XIEITE_HEADER_MACROS_COMPILER_TYPE
#	define XIEITE_HEADER_MACROS_COMPILER_TYPE

#	ifdef _ACC_
#		define XIEITE_COMPILER_TYPE_ACC
#	endif

#	ifdef __CMB__
#		define XIEITE_COMPILER_TYPE_MICROBLAZE
#	endif

#	ifdef __CHC__
#		define XIEITE_COMPILER_TYPE_C_TO_HARDWARE
#	endif

#	ifdef __ACK__
#		define XIEITE_COMPILER_TYPE_AMSTERDAM_COMPILER_KIT
#	endif

#	ifdef __CC_ARM
#		define XIEITE_COMPILER_TYPE_ARM
#	endif

#	if defined(AZTEC_C) || defined(__AZTEC_C__)
#		define XIEITE_COMPILER_TYPE_AZTEC
#	endif

#	if defined(__BORLANDC__) || defined(__CODEGEARC__)
#		define XIEITE_COMPILER_TYPE_BORLAND
#	endif

#	ifdef __CC65__
#		define XIEITE_COMPILER_TYPE_CC65
#	endif

#	ifdef __clang__
#		define XIEITE_COMPILER_TYPE_CLANG
#	endif

#	ifdef __COMO__
#		define XIEITE_COMPILER_TYPE_COMEAU
#	endif

#	ifdef __DECC
#		define XIEITE_COMPILER_TYPE_COMPAQ_C
#	endif

#	ifdef __DECCXX
#		define XIEITE_COMPILER_TYPE_COMPAQ_CPP
#	endif

#	ifdef __convexc__
#		define XIEITE_COMPILER_TYPE_CONVEX
#	endif

#	ifdef __COMPCERT__
#		define XIEITE_COMPILER_TYPE_COMPCERT
#	endif

#	ifdef __COVERITY__
#		define XIEITE_COMPILER_TYPE_COVERITY
#	endif

#	ifdef _CRAYC
#		define XIEITE_COMPILER_TYPE_CRAY
#	endif

#	ifdef __DCC__
#		define XIEITE_COMPILER_TYPE_DIAB
#	endif

#	ifdef _DICE
#		define XIEITE_COMPILER_TYPE_DICE
#	endif

#	ifdef __DMC__
#		define XIEITE_COMPILER_TYPE_DIGITAL_MARS
#	endif

#	ifdef __SYSC__
#		define XIEITE_COMPILER_TYPE_DIGNUS
#	endif

#	if defined(__DJGPP__) || defined(__GO32__)
#		define XIEITE_COMPILER_TYPE_DJGPP
#	endif

#	ifdef __EDG__
#		define XIEITE_COMPILER_TYPE_EDG
#	endif

#	ifdef __PATHCC__
#		define XIEITE_COMPILER_TYPE_EKOPATH
#	endif

#	ifdef __FCC_VERSION
#		define XIEITE_COMPILER_TYPE_FUJITSU
#	endif

#	ifdef __GNUC__
#		define XIEITE_COMPILER_TYPE_GCC
#	endif

#	ifdef __ghs__
#		define XIEITE_COMPILER_TYPE_GREEN_HILLS
#	endif

#	ifdef __HP_cc
#		define XIEITE_COMPILER_TYPE_ANSI
#	endif

#	ifdef __HP_aCC
#		define XIEITE_COMPILER_TYPE_ACPP
#	endif

#	ifdef __IAR_SYSTEMS_ICC__
#		define XIEITE_COMPILER_TYPE_IAR
#	endif

#	ifdef __ibmxl__
#		define XIEITE_COMPILER_TYPE_XL_CLANG
#	endif

#	ifdef __xlC__
#		define XIEITE_COMPILER_TYPE_XL_LEGACY
#	endif

#	ifdef __IBMC__
#		define XIEITE_COMPILER_TYPE_Z_OS_XL_C
#	endif

#	ifdef __IBMCPP__
#		define XIEITE_COMPILER_TYPE_Z_OS_XL_CPP
#	endif

#	ifdef __IMAGECRAFT__
#		define XIEITE_COMPILER_TYPE_IMAGECRAFT
#	endif

#	if defined(__INTEL_COMPILER) || defined(__ICL)
#		define XIEITE_COMPILER_TYPE_INTEL
#	endif

#	ifdef __KCC
#		define XIEITE_COMPILER_TYPE_KAI
#	endif

#	if defined(__CA__) || defined(__KEIL__)
#		define XIEITE_COMPILER_TYPE_CARM
#	endif

#	ifdef __C166__
#		define XIEITE_COMPILER_TYPE_C166
#	endif

#	if defined(__C51__) || defined(__CX51__)
#		define XIEITE_COMPILER_TYPE_C51
#	endif

#	ifdef __LCC__
#		define XIEITE_COMPILER_TYPE_LCC
#	endif

#	ifdef __llvm__
#		define XIEITE_COMPILER_TYPE_LLVM
#	endif

#	ifdef __HIGHC__
#		define XIEITE_COMPILER_TYPE_HIGH
#	endif

#	if defined(__MWERKS__) || defined(__CWCC__)
#		define XIEITE_COMPILER_TYPE_CODEWARRIOR
#	endif

#	ifdef _MSC_VER
#		define XIEITE_COMPILER_TYPE_MSVC
#	endif

#	ifdef _MRI
#		define XIEITE_COMPILER_TYPE_MICROTEC
#	endif

#	if defined(__NDPC__) || defined(__NDPX__)
#		define XIEITE_COMPILER_TYPE_NDP
#	endif

#	ifdef __MINGW32__
#		define XIEITE_COMPILER_TYPE_WINGW32
#	endif

#	ifdef __MINGW64__
#		define XIEITE_COMPILER_TYPE_WINGW64
#	endif

#	if defined(__sgi) || defined(sgi)
#		define XIEITE_COMPILER_TYPE_MIPSPRO
#	endif

#	ifdef MIRACLE
#		define XIEITE_COMPILER_TYPE_MIRACLE
#	endif

#	if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#		define XIEITE_COMPILER_TYPE_MACINTOSH_PROGRAMMERS_WORKSHOP
#	endif

#	ifdef __CC_NORCROFT
#		define XIEITE_COMPILER_TYPE_NORCROFT
#	endif

#	ifdef __NWCC__
#		define XIEITE_COMPILER_TYPE_NWCC
#	endif

#	if defined(__OPEN64__) || defined(__OPENCC__)
#		define XIEITE_COMPILER_TYPE_OPEN64
#	endif

#	ifdef ORA_PROC
#		define XIEITE_COMPILER_TYPE_PRO
#	endif

#	ifdef __SUNPRO_C
#		define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_C
#	endif

#	ifdef __SUNPRO_CC
#		define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_CPP
#	endif

#	ifdef __PACIFIC__
#		define XIEITE_COMPILER_TYPE_PACIFIC
#	endif

#	ifdef _PACC_VER
#		define XIEITE_COMPILER_TYPE_PALM
#	endif

#	ifdef __POCC__
#		define XIEITE_COMPILER_TYPE_PELLES
#	endif

#	ifdef __PGI
#		define XIEITE_COMPILER_TYPE_PORTLAND_GROUP
#	endif

#	if defined(__RENESAS__) || defined(__HITACHI__)
#		define XIEITE_COMPILER_TYPE_RENESAS
#	endif

#	if defined(SASC) || defined(__SASC) || defined(__SASC__)
#		define XIEITE_COMPILER_TYPE_SAS
#	endif

#	ifdef _SCO_DS
#		define XIEITE_COMPILER_TYPE_OPENSERVER
#	endif

#	ifdef SDCC
#		define XIEITE_COMPILER_TYPE_SMALL_DEVICE
#	endif

#	ifdef __SNC__
#		define XIEITE_COMPILER_TYPE_SN
#	endif

#	ifdef __VOSC__
#		define XIEITE_COMPILER_TYPE_VOS
#	endif

#	ifdef __SC__
#		define XIEITE_COMPILER_TYPE_SYMANTEC
#	endif

#	ifdef __TenDRA__
#		define XIEITE_COMPILER_TYPE_TENDRA
#	endif

#	if defined(__TI_COMPILER_VERION__) || defined(_TMS320C6X)
#		define XIEITE_COMPILER_TYPE_TMS320
#	endif

#	if defined(THINKC3) || defined(THINKC4)
#		define XIEITE_COMPILER_TYPE_THINK
#	endif

#	ifdef __TINYC__
#		define XIEITE_COMPILER_TYPE_TINY
#	endif

#	ifdef __TURBOC__
#		define XIEITE_COMPILER_TYPE_TURBO
#	endif

#	ifdef _UCC
#		define XIEITE_COMPILER_TYPE_ULTIMATE
#	endif

#	ifdef __USLC__
#		define XIEITE_COMPILER_TYPE_USL
#	endif

#	ifdef __VBCC__
#		define XIEITE_COMPILER_TYPE_VBCC
#	endif

#	ifdef __WATCOMC__
#		define XIEITE_COMPILER_TYPE_WATCOM
#	endif

#	ifdef __ZTC__
#		define XIEITE_COMPILER_TYPE_ZORTECH
#	endif

#endif
