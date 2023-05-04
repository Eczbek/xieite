#pragma once

#if defined(_ACC_)
#	define XIEITE_COMPILER_TYPE_ACC
#endif
#if defined(__CMB__)
#	define XIEITE_COMPILER_TYPE_MICROBLAZE
#endif
#if defined(__CHC__)
#	define XIEITE_COMPILER_TYPE_C_TO_HARDWARE
#endif
#if defined(__ACK__)
#	define XIEITE_COMPILER_TYPE_AMSTERDAM_COMPILER_KIT
#endif
#if defined(__CC_ARM)
#	define XIEITE_COMPILER_TYPE_ARM
#endif
#if defined(AZTEC_C) || defined(__AZTEC_C__)
#	define XIEITE_COMPILER_TYPE_AZTEC
#endif
#if defined(__BORLANDC__) || defined(__CODEGEARC__)
#	define XIEITE_COMPILER_TYPE_BORLAND
#endif
#if defined(__CC65__)
#	define XIEITE_COMPILER_TYPE_CC65
#endif
#if defined(__clang__)
#	define XIEITE_COMPILER_TYPE_CLANG
#endif
#if defined(__COMO__)
#	define XIEITE_COMPILER_TYPE_COMEAU
#endif
#if defined(__DECC)
#	define XIEITE_COMPILER_TYPE_COMPAQ_C
#endif
#if defined(__DECCXX)
#	define XIEITE_COMPILER_TYPE_COMPAQ_CPP
#endif
#if defined(__convexc__)
#	define XIEITE_COMPILER_TYPE_CONVEX
#endif
#if defined(__COMPCERT__)
#	define XIEITE_COMPILER_TYPE_COMPCERT
#endif
#if defined(__COVERITY__)
#	define XIEITE_COMPILER_TYPE_COVERITY
#endif
#if defined(_CRAYC)
#	define XIEITE_COMPILER_TYPE_CRAY
#endif
#if defined(__DCC__)
#	define XIEITE_COMPILER_TYPE_DIAB
#endif
#if defined(_DICE)
#	define XIEITE_COMPILER_TYPE_DICE
#endif
#if defined(__DMC__)
#	define XIEITE_COMPILER_TYPE_DIGITAL_MARS
#endif
#if defined(__SYSC__)
#	define XIEITE_COMPILER_TYPE_DIGNUS
#endif
#if defined(__DJGPP__) || defined(__GO32__)
#	define XIEITE_COMPILER_TYPE_DJGPP
#endif
#if defined(__EDG__)
#	define XIEITE_COMPILER_TYPE_EDG
#endif
#if defined(__PATHCC__)
#	define XIEITE_COMPILER_TYPE_EKOPATH
#endif
#if defined(__FCC_VERSION)
#	define XIEITE_COMPILER_TYPE_FUJITSU
#endif
#if defined(__GNUC__)
#	define XIEITE_COMPILER_TYPE_GCC
#endif
#if defined(__ghs__)
#	define XIEITE_COMPILER_TYPE_GREEN_HILLS
#endif
#if defined(__HP_cc)
#	define XIEITE_COMPILER_TYPE_ANSI
#endif
#if defined(__HP_aCC)
#	define XIEITE_COMPILER_TYPE_ACPP
#endif
#if defined(__IAR_SYSTEMS_ICC__)
#	define XIEITE_COMPILER_TYPE_IAR
#endif
#if defined(__ibmxl__)
#	define XIEITE_COMPILER_TYPE_XL_CLANG
#endif
#if defined(__xlC__)
#	define XIEITE_COMPILER_TYPE_XL_LEGACY
#endif
#if defined(__IBMC__)
#	define XIEITE_COMPILER_TYPE_Z_OS_XL_C
#endif
#if defined(__IBMCPP__)
#	define XIEITE_COMPILER_TYPE_Z_OS_XL_CPP
#endif
#if defined(__IMAGECRAFT__)
#	define XIEITE_COMPILER_TYPE_IMAGECRAFT
#endif
#if defined(__INTEL_COMPILER) || defined(__ICL)
#	define XIEITE_COMPILER_TYPE_INTEL
#endif
#if defined(__KCC)
#	define XIEITE_COMPILER_TYPE_KAI
#endif
#if defined(__CA__) || defined(__KEIL__)
#	define XIEITE_COMPILER_TYPE_CARM
#endif
#if defined(__C166__)
#	define XIEITE_COMPILER_TYPE_C166
#endif
#if defined(__C51__) || defined(__CX51__)
#	define XIEITE_COMPILER_TYPE_C51
#endif
#if defined(__LCC__)
#	define XIEITE_COMPILER_TYPE_LCC
#endif
#if defined(__llvm__)
#	define XIEITE_COMPILER_TYPE_LLVM
#endif
#if defined(__HIGHC__)
#	define XIEITE_COMPILER_TYPE_HIGH
#endif
#if defined(__MWERKS__) || defined(__CWCC__)
#	define XIEITE_COMPILER_TYPE_CODEWARRIOR
#endif
#if defined(_MSC_VER)
#	define XIEITE_COMPILER_TYPE_VISUAL
#endif
#if defined(_MRI)
#	define XIEITE_COMPILER_TYPE_MICROTEC
#endif
#if defined(__NDPC__) || defined(__NDPX__)
#	define XIEITE_COMPILER_TYPE_NDP
#endif
#if defined(__MINGW32__)
#	define XIEITE_COMPILER_TYPE_WINGW32
#endif
#if defined(__MINGW64__)
#	define XIEITE_COMPILER_TYPE_WINGW64
#endif
#if defined(__sgi) || defined(sgi)
#	define XIEITE_COMPILER_TYPE_MIPSPRO
#endif
#if defined(MIRACLE)
#	define XIEITE_COMPILER_TYPE_MIRACLE
#endif
#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
#	define XIEITE_COMPILER_TYPE_MACINTOSH_PROGRAMMERS_WORKSHOP
#endif
#if defined(__CC_NORCROFT)
#	define XIEITE_COMPILER_TYPE_NORCROFT
#endif
#if defined(__NWCC__)
#	define XIEITE_COMPILER_TYPE_NWCC
#endif
#if defined(__OPEN64__) || defined(__OPENCC__)
#	define XIEITE_COMPILER_TYPE_OPEN64
#endif
#if defined(ORA_PROC)
#	define XIEITE_COMPILER_TYPE_PRO
#endif
#if defined(__SUNPRO_C)
#	define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_C
#endif
#if defined(__SUNPRO_CC)
#	define XIEITE_COMPILER_TYPE_SOLARIS_STUDIO_CPP
#endif
#if defined(__PACIFIC__)
#	define XIEITE_COMPILER_TYPE_PACIFIC
#endif
#if defined(_PACC_VER)
#	define XIEITE_COMPILER_TYPE_PALM
#endif
#if defined(__POCC__)
#	define XIEITE_COMPILER_TYPE_PELLES
#endif
#if defined(__PGI)
#	define XIEITE_COMPILER_TYPE_PORTLAND_GROUP
#endif
#if defined(__RENESAS__) || defined(__HITACHI__)
#	define XIEITE_COMPILER_TYPE_RENESAS
#endif
#if defined(SASC) || defined(__SASC) || defined(__SASC__)
#	define XIEITE_COMPILER_TYPE_SAS
#endif
#if defined(_SCO_DS)
#	define XIEITE_COMPILER_TYPE_OPENSERVER
#endif
#if defined(SDCC)
#	define XIEITE_COMPILER_TYPE_SMALL_DEVICE
#endif
#if defined(__SNC__)
#	define XIEITE_COMPILER_TYPE_SN
#endif
#if defined(__VOSC__)
#	define XIEITE_COMPILER_TYPE_VOS
#endif
#if defined(__SC__)
#	define XIEITE_COMPILER_TYPE_SYMANTEC
#endif
#if defined(__TenDRA__)
#	define XIEITE_COMPILER_TYPE_TENDRA
#endif
#if defined(__TI_COMPILER_VERION__) || defined(_TMS320C6X)
#	define XIEITE_COMPILER_TYPE_TMS320
#endif
#if defined(THINKC3) || defined(THINKC4)
#	define XIEITE_COMPILER_TYPE_THINK
#endif
#if defined(__TINYC__)
#	define XIEITE_COMPILER_TYPE_TINY
#endif
#if defined(__TURBOC__)
#	define XIEITE_COMPILER_TYPE_TURBO
#endif
#if defined(_UCC)
#	define XIEITE_COMPILER_TYPE_ULTIMATE
#endif
#if defined(__USLC__)
#	define XIEITE_COMPILER_TYPE_USL
#endif
#if defined(__VBCC__)
#	define XIEITE_COMPILER_TYPE_VBCC
#endif
#if defined(__WATCOMC__)
#	define XIEITE_COMPILER_TYPE_WATCOM
#endif
#if defined(__ZTC__)
#	define XIEITE_COMPILER_TYPE_ZORTECH
#endif
