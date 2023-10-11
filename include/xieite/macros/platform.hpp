#ifndef XIEITE_HEADER_MACROS_PLATFORM
#	define XIEITE_HEADER_MACROS_PLATFORM

#	undef XIEITE_PLATFORM_AEGIS
#	undef XIEITE_PLATFORM_AIX
#	undef XIEITE_PLATFORM_AMIGAOS
#	undef XIEITE_PLATFORM_ANDROID
#	undef XIEITE_PLATFORM_BEOS
#	undef XIEITE_PLATFORM_BLUE_GENE
#	undef XIEITE_PLATFORM_BSD
#	undef XIEITE_PLATFORM_BSD_OS
#	undef XIEITE_PLATFORM_CONVEXOS
#	undef XIEITE_PLATFORM_DC_OSX
#	undef XIEITE_PLATFORM_DG_UX
#	undef XIEITE_PLATFORM_DOMAIN_OS
#	undef XIEITE_PLATFORM_DRAGONFLY
#	undef XIEITE_PLATFORM_DYNIX
#	undef XIEITE_PLATFORM_ECOS
#	undef XIEITE_PLATFORM_EMX
#	undef XIEITE_PLATFORM_FREEBSD
#	undef XIEITE_PLATFORM_GNU_HURD
#	undef XIEITE_PLATFORM_GNU_KFREEBSD
#	undef XIEITE_PLATFORM_GNU_LINUX
#	undef XIEITE_PLATFORM_HI_UX_MPP
#	undef XIEITE_PLATFORM_INTEGRITY
#	undef XIEITE_PLATFORM_INTERIX
#	undef XIEITE_PLATFORM_IRIX
#	undef XIEITE_PLATFORM_LINUX
#	undef XIEITE_PLATFORM_LYNXOS
#	undef XIEITE_PLATFORM_MACINTOSH
#	undef XIEITE_PLATFORM_MINIX
#	undef XIEITE_PLATFORM_MORPHOS
#	undef XIEITE_PLATFORM_MPE_IX
#	undef XIEITE_PLATFORM_MS_DOS
#	undef XIEITE_PLATFORM_NETBSD
#	undef XIEITE_PLATFORM_NONSTOP
#	undef XIEITE_PLATFORM_NUCLEUS_RTOS
#	undef XIEITE_PLATFORM_OPENBSD
#	undef XIEITE_PLATFORM_OPENSERVER
#	undef XIEITE_PLATFORM_OS_2
#	undef XIEITE_PLATFORM_OS_400
#	undef XIEITE_PLATFORM_OS_9
#	undef XIEITE_PLATFORM_PALM_OS
#	undef XIEITE_PLATFORM_PLAN_9
#	undef XIEITE_PLATFORM_QNX
#	undef XIEITE_PLATFORM_SINIX
#	undef XIEITE_PLATFORM_SOLARIS
#	undef XIEITE_PLATFORM_SYGWIN
#	undef XIEITE_PLATFORM_SYLLABLE
#	undef XIEITE_PLATFORM_SYMBIAN
#	undef XIEITE_PLATFORM_SYSTEM_V
#	undef XIEITE_PLATFORM_TRU64
#	undef XIEITE_PLATFORM_ULTRIX
#	undef XIEITE_PLATFORM_UNICOS
#	undef XIEITE_PLATFORM_UNICOS_MP
#	undef XIEITE_PLATFORM_UNIX
#	undef XIEITE_PLATFORM_UNIXWARE
#	undef XIEITE_PLATFORM_UTS
#	undef XIEITE_PLATFORM_UWIN
#	undef XIEITE_PLATFORM_VMS
#	undef XIEITE_PLATFORM_VOS
#	undef XIEITE_PLATFORM_VXWORKS
#	undef XIEITE_PLATFORM_WINDOWS
#	undef XIEITE_PLATFORM_WINDOWS_CE
#	undef XIEITE_PLATFORM_WIND_U
#	undef XIEITE_PLATFORM_Z_OS

#	ifdef aegis
#		define XIEITE_PLATFORM_AEGIS true
#	endif

#	ifdef _AIX
#		define XIEITE_PLATFORM_AIX true
#	endif

#	if defined(AMIGA) || defined(__amigaos__)
#		define XIEITE_PLATFORM_AMIGAOS true
#	endif

#	ifdef __ANDROID__
#		define XIEITE_PLATFORM_ANDROID true
#	endif

#	ifdef __BEOS__
#		define XIEITE_PLATFORM_BEOS true
#	endif

#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		define XIEITE_PLATFORM_BLUE_GENE true
#	endif

#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		define XIEITE_PLATFORM_BSD true
#	endif

#	ifdef __bsdi__
#		define XIEITE_PLATFORM_BSD_OS true
#	endif

#	ifdef __convex__
#		define XIEITE_PLATFORM_CONVEXOS true
#	endif

#	ifdef pyr
#		define XIEITE_PLATFORM_DC_OSX true
#	endif

#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		define XIEITE_PLATFORM_DG_UX true
#	endif

#	ifdef apollo
#		define XIEITE_PLATFORM_DOMAIN_OS true
#	endif

#	ifdef __DragonFly__
#		define XIEITE_PLATFORM_DRAGONFLY true
#	endif

#	if defined(_SEQUENT_) || defined(sequent)
#		define XIEITE_PLATFORM_DYNIX true
#	endif

#	ifdef __ECOS
#		define XIEITE_PLATFORM_ECOS true
#	endif

#	ifdef __EMX__
#		define XIEITE_PLATFORM_EMX true
#	endif

#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		define XIEITE_PLATFORM_FREEBSD true
#	endif

#	if defined(__GNU__) || defined(__gnu_hurd__)
#		define XIEITE_PLATFORM_GNU_HURD true
#	endif

#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		define XIEITE_PLATFORM_GNU_KFREEBSD true
#	endif

#	ifdef __gnu_linux__
#		define XIEITE_PLATFORM_GNU_LINUX true
#	endif

#	ifdef __hiuxmpp
#		define XIEITE_PLATFORM_HI_UX_MPP true
#	endif

#	ifdef __INTEGRITY
#		define XIEITE_PLATFORM_INTEGRITY true
#	endif

#	ifdef __INTERIX
#		define XIEITE_PLATFORM_INTERIX true
#	endif

#	if defined(sgi) || defined(__sgi)
#		define XIEITE_PLATFORM_IRIX true
#	endif

#	ifdef __linux__
#		define XIEITE_PLATFORM_LINUX true
#	endif

#	ifdef __Lynx__
#		define XIEITE_PLATFORM_LYNXOS true
#	endif

#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		define XIEITE_PLATFORM_MACINTOSH true
#	endif

#	ifdef __minix
#		define XIEITE_PLATFORM_MINIX true
#	endif

#	ifdef __MORPHOS__
#		define XIEITE_PLATFORM_MORPHOS true
#	endif

#	if defined(mpeix) || defined(__mpexl)
#		define XIEITE_PLATFORM_MPE_IX true
#	endif

#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		define XIEITE_PLATFORM_MS_DOS true
#	endif

#	ifdef __NetBSD__
#		define XIEITE_PLATFORM_NETBSD true
#	endif

#	ifdef __TANDEM
#		define XIEITE_PLATFORM_NONSTOP true
#	endif

#	ifdef __nucleus__
#		define XIEITE_PLATFORM_NUCLEUS_RTOS true
#	endif

#	ifdef __OpenBSD__
#		define XIEITE_PLATFORM_OPENBSD true
#	endif

#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		define XIEITE_PLATFORM_OPENSERVER true
#	endif

#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		define XIEITE_PLATFORM_OS_2 true
#	endif

#	ifdef __OS400__
#		define XIEITE_PLATFORM_OS_400 true
#	endif

#	if defined(__OS9000) || defined(_OSK)
#		define XIEITE_PLATFORM_OS_9 true
#	endif

#	ifdef __palmos__
#		define XIEITE_PLATFORM_PALM_OS true
#	endif

#	ifdef EPLAN9
#		define XIEITE_PLATFORM_PLAN_9 true
#	endif

#	if defined(__QNX__) || defined(__QNXNTO__)
#		define XIEITE_PLATFORM_QNX true
#	endif

#	ifdef sinux
#		define XIEITE_PLATFORM_SINIX true
#	endif

#	if defined(sun) || defined(__sun)
#		define XIEITE_PLATFORM_SOLARIS true
#	endif

#	ifdef __SYGWIN__
#		define XIEITE_PLATFORM_SYGWIN true
#	endif

#	ifdef __SYLLABLE__
#		define XIEITE_PLATFORM_SYLLABLE true
#	endif

#	ifdef __SYMBIAN32__
#		define XIEITE_PLATFORM_SYMBIAN true
#	endif

#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		define XIEITE_PLATFORM_SYSTEM_V true
#	endif

#	if defined(__osf__) || defined(__osf)
#		define XIEITE_PLATFORM_TRU64 true
#	endif

#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		define XIEITE_PLATFORM_ULTRIX true
#	endif

#	ifdef _UNICOS
#		define XIEITE_PLATFORM_UNICOS true
#	endif

#	if defined(_CRAY) || defined(__crayx1)
#		define XIEITE_PLATFORM_UNICOS_MP true
#	endif

#	if defined(__unix__) || defined(__unix)
#		define XIEITE_PLATFORM_UNIX true
#	endif

#	if defined(sco) || defined(_UNIXWARE7)
#		define XIEITE_PLATFORM_UNIXWARE true
#	endif

#	ifdef UTS
#		define XIEITE_PLATFORM_UTS true
#	endif

#	ifdef _UWIN
#		define XIEITE_PLATFORM_UWIN true
#	endif

#	if defined(VMS) || defined(__VMS)
#		define XIEITE_PLATFORM_VMS true
#	endif

#	ifdef __VOS__
#		define XIEITE_PLATFORM_VOS true
#	endif

#	if defined(__VXWORKS__) || defined(__vxworks)
#		define XIEITE_PLATFORM_VXWORKS true
#	endif

#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		define XIEITE_PLATFORM_WINDOWS true
#	endif

#	ifdef _WIN32_WCE
#		define XIEITE_PLATFORM_WINDOWS_CE true
#	endif

#	ifdef _WINDU_SOURCE
#		define XIEITE_PLATFORM_WIND_U true
#	endif

#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		define XIEITE_PLATFORM_Z_OS true
#	endif

#endif
