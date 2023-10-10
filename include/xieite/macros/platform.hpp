#pragma once

#define XIEITE_PLATFORM_AEGIS false
#define XIEITE_PLATFORM_AIX false
#define XIEITE_PLATFORM_AMIGAOS false
#define XIEITE_PLATFORM_ANDROID false
#define XIEITE_PLATFORM_BEOS false
#define XIEITE_PLATFORM_BLUE_GENE false
#define XIEITE_PLATFORM_BSD false
#define XIEITE_PLATFORM_BSD_OS false
#define XIEITE_PLATFORM_CONVEXOS false
#define XIEITE_PLATFORM_DC_OSX false
#define XIEITE_PLATFORM_DG_UX false
#define XIEITE_PLATFORM_DOMAIN_OS false
#define XIEITE_PLATFORM_DRAGONFLY false
#define XIEITE_PLATFORM_DYNIX false
#define XIEITE_PLATFORM_ECOS false
#define XIEITE_PLATFORM_EMX false
#define XIEITE_PLATFORM_FREEBSD false
#define XIEITE_PLATFORM_GNU_HURD false
#define XIEITE_PLATFORM_GNU_KFREEBSD false
#define XIEITE_PLATFORM_GNU_LINUX false
#define XIEITE_PLATFORM_HI_UX_MPP false
#define XIEITE_PLATFORM_INTEGRITY false
#define XIEITE_PLATFORM_INTERIX false
#define XIEITE_PLATFORM_IRIX false
#define XIEITE_PLATFORM_LINUX false
#define XIEITE_PLATFORM_LYNXOS false
#define XIEITE_PLATFORM_MACINTOSH false
#define XIEITE_PLATFORM_MINIX false
#define XIEITE_PLATFORM_MORPHOS false
#define XIEITE_PLATFORM_MPE_IX false
#define XIEITE_PLATFORM_MS_DOS false
#define XIEITE_PLATFORM_NETBSD false
#define XIEITE_PLATFORM_NONSTOP false
#define XIEITE_PLATFORM_NUCLEUS_RTOS false
#define XIEITE_PLATFORM_OPENBSD false
#define XIEITE_PLATFORM_OPENSERVER false
#define XIEITE_PLATFORM_OS_2 false
#define XIEITE_PLATFORM_OS_400 false
#define XIEITE_PLATFORM_OS_9 false
#define XIEITE_PLATFORM_PALM_OS false
#define XIEITE_PLATFORM_PLAN_9 false
#define XIEITE_PLATFORM_QNX false
#define XIEITE_PLATFORM_SINIX false
#define XIEITE_PLATFORM_SOLARIS false
#define XIEITE_PLATFORM_SYGWIN false
#define XIEITE_PLATFORM_SYLLABLE false
#define XIEITE_PLATFORM_SYMBIAN false
#define XIEITE_PLATFORM_SYSTEM_V false
#define XIEITE_PLATFORM_TRU64 false
#define XIEITE_PLATFORM_ULTRIX false
#define XIEITE_PLATFORM_UNICOS false
#define XIEITE_PLATFORM_UNICOS_MP false
#define XIEITE_PLATFORM_UNIX false
#define XIEITE_PLATFORM_UNIXWARE false
#define XIEITE_PLATFORM_UTS false
#define XIEITE_PLATFORM_UWIN false
#define XIEITE_PLATFORM_VMS false
#define XIEITE_PLATFORM_VOS false
#define XIEITE_PLATFORM_VXWORKS false
#define XIEITE_PLATFORM_WINDOWS false
#define XIEITE_PLATFORM_WINDOWS_CE false
#define XIEITE_PLATFORM_WIND_U false
#define XIEITE_PLATFORM_Z_OS false

#ifdef aegis
#	undef XIEITE_PLATFORM_AEGIS
#	define XIEITE_PLATFORM_AEGIS true
#endif

#ifdef _AIX
#	undef XIEITE_PLATFORM_AIX
#	define XIEITE_PLATFORM_AIX true
#endif

#if defined(AMIGA) || defined(__amigaos__)
#	undef XIEITE_PLATFORM_AMIGAOS
#	define XIEITE_PLATFORM_AMIGAOS true
#endif

#ifdef __ANDROID__
#	undef XIEITE_PLATFORM_ANDROID
#	define XIEITE_PLATFORM_ANDROID true
#endif

#ifdef __BEOS__
#	undef XIEITE_PLATFORM_BEOS
#	define XIEITE_PLATFORM_BEOS true
#endif

#if defined(__bg__) || defined(__THW_BLUEGENE__)
#	undef XIEITE_PLATFORM_BLUE_GENE
#	define XIEITE_PLATFORM_BLUE_GENE true
#endif

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#	undef XIEITE_PLATFORM_BSD
#	define XIEITE_PLATFORM_BSD true
#endif

#ifdef __bsdi__
#	undef XIEITE_PLATFORM_BSD_OS
#	define XIEITE_PLATFORM_BSD_OS true
#endif

#ifdef __convex__
#	undef XIEITE_PLATFORM_CONVEXOS
#	define XIEITE_PLATFORM_CONVEXOS true
#endif

#ifdef pyr
#	undef XIEITE_PLATFORM_DC_OSX
#	define XIEITE_PLATFORM_DC_OSX true
#endif

#if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#	undef XIEITE_PLATFORM_DG_UX
#	define XIEITE_PLATFORM_DG_UX true
#endif

#ifdef apollo
#	undef XIEITE_PLATFORM_DOMAIN_OS
#	define XIEITE_PLATFORM_DOMAIN_OS true
#endif

#ifdef __DragonFly__
#	undef XIEITE_PLATFORM_DRAGONFLY
#	define XIEITE_PLATFORM_DRAGONFLY true
#endif

#if defined(_SEQUENT_) || defined(sequent)
#	undef XIEITE_PLATFORM_DYNIX
#	define XIEITE_PLATFORM_DYNIX true
#endif

#ifdef __ECOS
#	undef XIEITE_PLATFORM_ECOS
#	define XIEITE_PLATFORM_ECOS true
#endif

#ifdef __EMX__
#	undef XIEITE_PLATFORM_EMX
#	define XIEITE_PLATFORM_EMX true
#endif

#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#	undef XIEITE_PLATFORM_FREEBSD
#	define XIEITE_PLATFORM_FREEBSD true
#endif

#if defined(__GNU__) || defined(__gnu_hurd__)
#	undef XIEITE_PLATFORM_GNU_HURD
#	define XIEITE_PLATFORM_GNU_HURD true
#endif

#if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#	undef XIEITE_PLATFORM_GNU_KFREEBSD
#	define XIEITE_PLATFORM_GNU_KFREEBSD true
#endif

#ifdef __gnu_linux__
#	undef XIEITE_PLATFORM_GNU_LINUX
#	define XIEITE_PLATFORM_GNU_LINUX true
#endif

#ifdef __hiuxmpp
#	undef XIEITE_PLATFORM_HI_UX_MPP
#	define XIEITE_PLATFORM_HI_UX_MPP true
#endif

#ifdef __INTEGRITY
#	undef XIEITE_PLATFORM_INTEGRITY
#	define XIEITE_PLATFORM_INTEGRITY true
#endif

#ifdef __INTERIX
#	undef XIEITE_PLATFORM_INTERIX
#	define XIEITE_PLATFORM_INTERIX true
#endif

#if defined(sgi) || defined(__sgi)
#	undef XIEITE_PLATFORM_IRIX
#	define XIEITE_PLATFORM_IRIX true
#endif

#ifdef __linux__
#	undef XIEITE_PLATFORM_LINUX
#	define XIEITE_PLATFORM_LINUX true
#endif

#ifdef __Lynx__
#	undef XIEITE_PLATFORM_LYNXOS
#	define XIEITE_PLATFORM_LYNXOS true
#endif

#if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#	undef XIEITE_PLATFORM_MACINTOSH
#	define XIEITE_PLATFORM_MACINTOSH true
#endif

#ifdef __minix
#	undef XIEITE_PLATFORM_MINIX
#	define XIEITE_PLATFORM_MINIX true
#endif

#ifdef __MORPHOS__
#	undef XIEITE_PLATFORM_MORPHOS
#	define XIEITE_PLATFORM_MORPHOS true
#endif

#if defined(mpeix) || defined(__mpexl)
#	undef XIEITE_PLATFORM_MPE_IX
#	define XIEITE_PLATFORM_MPE_IX true
#endif

#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#	undef XIEITE_PLATFORM_MS_DOS
#	define XIEITE_PLATFORM_MS_DOS true
#endif

#ifdef __NetBSD__
#	undef XIEITE_PLATFORM_NETBSD
#	define XIEITE_PLATFORM_NETBSD true
#endif

#ifdef __TANDEM
#	undef XIEITE_PLATFORM_NONSTOP
#	define XIEITE_PLATFORM_NONSTOP true
#endif

#ifdef __nucleus__
#	undef XIEITE_PLATFORM_NUCLEUS_RTOS
#	define XIEITE_PLATFORM_NUCLEUS_RTOS true
#endif

#ifdef __OpenBSD__
#	undef XIEITE_PLATFORM_OPENBSD
#	define XIEITE_PLATFORM_OPENBSD true
#endif

#if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#	undef XIEITE_PLATFORM_OPENSERVER
#	define XIEITE_PLATFORM_OPENSERVER true
#endif

#if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#	undef XIEITE_PLATFORM_OS_2
#	define XIEITE_PLATFORM_OS_2 true
#endif

#ifdef __OS400__
#	undef XIEITE_PLATFORM_OS_400
#	define XIEITE_PLATFORM_OS_400 true
#endif

#if defined(__OS9000) || defined(_OSK)
#	undef XIEITE_PLATFORM_OS_9
#	define XIEITE_PLATFORM_OS_9 true
#endif

#ifdef __palmos__
#	undef XIEITE_PLATFORM_PALM_OS
#	define XIEITE_PLATFORM_PALM_OS true
#endif

#ifdef EPLAN9
#	undef XIEITE_PLATFORM_PLAN_9
#	define XIEITE_PLATFORM_PLAN_9 true
#endif

#if defined(__QNX__) || defined(__QNXNTO__)
#	undef XIEITE_PLATFORM_QNX
#	define XIEITE_PLATFORM_QNX true
#endif

#ifdef sinux
#	undef XIEITE_PLATFORM_SINIX
#	define XIEITE_PLATFORM_SINIX true
#endif

#if defined(sun) || defined(__sun)
#	undef XIEITE_PLATFORM_SOLARIS
#	define XIEITE_PLATFORM_SOLARIS true
#endif

#ifdef __SYGWIN__
#	undef XIEITE_PLATFORM_SYGWIN
#	define XIEITE_PLATFORM_SYGWIN true
#endif

#ifdef __SYLLABLE__
#	undef XIEITE_PLATFORM_SYLLABLE
#	define XIEITE_PLATFORM_SYLLABLE true
#endif

#ifdef __SYMBIAN32__
#	undef XIEITE_PLATFORM_SYMBIAN
#	define XIEITE_PLATFORM_SYMBIAN true
#endif

#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#	undef XIEITE_PLATFORM_SYSTEM_V
#	define XIEITE_PLATFORM_SYSTEM_V true
#endif

#if defined(__osf__) || defined(__osf)
#	undef XIEITE_PLATFORM_TRU64
#	define XIEITE_PLATFORM_TRU64 true
#endif

#if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#	undef XIEITE_PLATFORM_ULTRIX
#	define XIEITE_PLATFORM_ULTRIX true
#endif

#ifdef _UNICOS
#	undef XIEITE_PLATFORM_UNICOS
#	define XIEITE_PLATFORM_UNICOS true
#endif

#if defined(_CRAY) || defined(__crayx1)
#	undef XIEITE_PLATFORM_UNICOS_MP
#	define XIEITE_PLATFORM_UNICOS_MP true
#endif

#if defined(__unix__) || defined(__unix)
#	undef XIEITE_PLATFORM_UNIX
#	define XIEITE_PLATFORM_UNIX true
#endif

#if defined(sco) || defined(_UNIXWARE7)
#	undef XIEITE_PLATFORM_UNIXWARE
#	define XIEITE_PLATFORM_UNIXWARE true
#endif

#ifdef UTS
#	undef XIEITE_PLATFORM_UTS
#	define XIEITE_PLATFORM_UTS true
#endif

#ifdef _UWIN
#	undef XIEITE_PLATFORM_UWIN
#	define XIEITE_PLATFORM_UWIN true
#endif

#if defined(VMS) || defined(__VMS)
#	undef XIEITE_PLATFORM_VMS
#	define XIEITE_PLATFORM_VMS true
#endif

#ifdef __VOS__
#	undef XIEITE_PLATFORM_VOS
#	define XIEITE_PLATFORM_VOS true
#endif

#if defined(__VXWORKS__) || defined(__vxworks)
#	undef XIEITE_PLATFORM_VXWORKS
#	define XIEITE_PLATFORM_VXWORKS true
#endif

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#	undef XIEITE_PLATFORM_WINDOWS
#	define XIEITE_PLATFORM_WINDOWS true
#endif

#ifdef _WIN32_WCE
#	undef XIEITE_PLATFORM_WINDOWS_CE
#	define XIEITE_PLATFORM_WINDOWS_CE true
#endif

#ifdef _WINDU_SOURCE
#	undef XIEITE_PLATFORM_WIND_U
#	define XIEITE_PLATFORM_WIND_U true
#endif

#if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#	undef XIEITE_PLATFORM_Z_OS
#	define XIEITE_PLATFORM_Z_OS true
#endif
