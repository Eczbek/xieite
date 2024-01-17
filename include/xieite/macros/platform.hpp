#ifndef XIEITE_HEADER_MACROS_PLATFORM
#	define XIEITE_HEADER_MACROS_PLATFORM

#	define XIEITE_PLATFORM_AEGIS 0
#	define XIEITE_PLATFORM_AIX 0
#	define XIEITE_PLATFORM_AMIGAOS 0
#	define XIEITE_PLATFORM_ANDROID 0
#	define XIEITE_PLATFORM_BEOS 0
#	define XIEITE_PLATFORM_BLUE_GENE 0
#	define XIEITE_PLATFORM_BSD 0
#	define XIEITE_PLATFORM_BSD_OS 0
#	define XIEITE_PLATFORM_CONVEXOS 0
#	define XIEITE_PLATFORM_DC_OSX 0
#	define XIEITE_PLATFORM_DG_UX 0
#	define XIEITE_PLATFORM_DOMAIN_OS 0
#	define XIEITE_PLATFORM_DRAGONFLY 0
#	define XIEITE_PLATFORM_DYNIX 0
#	define XIEITE_PLATFORM_ECOS 0
#	define XIEITE_PLATFORM_EMX 0
#	define XIEITE_PLATFORM_FREEBSD 0
#	define XIEITE_PLATFORM_GNU_HURD 0
#	define XIEITE_PLATFORM_GNU_KFREEBSD 0
#	define XIEITE_PLATFORM_GNU_LINUX 0
#	define XIEITE_PLATFORM_HI_UX_MPP 0
#	define XIEITE_PLATFORM_INTEGRITY 0
#	define XIEITE_PLATFORM_INTERIX 0
#	define XIEITE_PLATFORM_IRIX 0
#	define XIEITE_PLATFORM_LINUX 0
#	define XIEITE_PLATFORM_LYNXOS 0
#	define XIEITE_PLATFORM_MACINTOSH 0
#	define XIEITE_PLATFORM_MINIX 0
#	define XIEITE_PLATFORM_MORPHOS 0
#	define XIEITE_PLATFORM_MPE_IX 0
#	define XIEITE_PLATFORM_MS_DOS 0
#	define XIEITE_PLATFORM_NETBSD 0
#	define XIEITE_PLATFORM_NONSTOP 0
#	define XIEITE_PLATFORM_NUCLEUS_RTOS 0
#	define XIEITE_PLATFORM_OPENBSD 0
#	define XIEITE_PLATFORM_OPENSERVER 0
#	define XIEITE_PLATFORM_OS_2 0
#	define XIEITE_PLATFORM_OS_400 0
#	define XIEITE_PLATFORM_OS_9 0
#	define XIEITE_PLATFORM_PALM_OS 0
#	define XIEITE_PLATFORM_PLAN_9 0
#	define XIEITE_PLATFORM_QNX 0
#	define XIEITE_PLATFORM_SINIX 0
#	define XIEITE_PLATFORM_SOLARIS 0
#	define XIEITE_PLATFORM_SYGWIN 0
#	define XIEITE_PLATFORM_SYLLABLE 0
#	define XIEITE_PLATFORM_SYMBIAN 0
#	define XIEITE_PLATFORM_SYSTEM_V 0
#	define XIEITE_PLATFORM_TRU64 0
#	define XIEITE_PLATFORM_ULTRIX 0
#	define XIEITE_PLATFORM_UNICOS 0
#	define XIEITE_PLATFORM_UNICOS_MP 0
#	define XIEITE_PLATFORM_UNIX 0
#	define XIEITE_PLATFORM_UNIXWARE 0
#	define XIEITE_PLATFORM_UTS 0
#	define XIEITE_PLATFORM_UWIN 0
#	define XIEITE_PLATFORM_VMS 0
#	define XIEITE_PLATFORM_VOS 0
#	define XIEITE_PLATFORM_VXWORKS 0
#	define XIEITE_PLATFORM_WINDOWS 0
#	define XIEITE_PLATFORM_WINDOWS_CE 0
#	define XIEITE_PLATFORM_WIND_U 0
#	define XIEITE_PLATFORM_Z_OS 0

#	ifdef aegis
#		undef XIEITE_PLATFORM_AEGIS
#		define XIEITE_PLATFORM_AEGIS 1
#	endif

#	ifdef _AIX
#		undef XIEITE_PLATFORM_AIX
#		define XIEITE_PLATFORM_AIX 1
#	endif

#	if defined(AMIGA) || defined(__amigaos__)
#		undef XIEITE_PLATFORM_AMIGAOS
#		define XIEITE_PLATFORM_AMIGAOS 1
#	endif

#	ifdef __ANDROID__
#		undef XIEITE_PLATFORM_ANDROID
#		define XIEITE_PLATFORM_ANDROID 1
#	endif

#	ifdef __BEOS__
#		undef XIEITE_PLATFORM_BEOS
#		define XIEITE_PLATFORM_BEOS 1
#	endif

#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		undef XIEITE_PLATFORM_BLUE_GENE
#		define XIEITE_PLATFORM_BLUE_GENE 1
#	endif

#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		undef XIEITE_PLATFORM_BSD
#		define XIEITE_PLATFORM_BSD 1
#	endif

#	ifdef __bsdi__
#		undef XIEITE_PLATFORM_BSD_OS
#		define XIEITE_PLATFORM_BSD_OS 1
#	endif

#	ifdef __convex__
#		undef XIEITE_PLATFORM_CONVEXOS
#		define XIEITE_PLATFORM_CONVEXOS 1
#	endif

#	ifdef pyr
#		undef XIEITE_PLATFORM_DC_OSX
#		define XIEITE_PLATFORM_DC_OSX 1
#	endif

#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		undef XIEITE_PLATFORM_DG_UX
#		define XIEITE_PLATFORM_DG_UX 1
#	endif

#	ifdef apollo
#		undef XIEITE_PLATFORM_DOMAIN_OS
#		define XIEITE_PLATFORM_DOMAIN_OS 1
#	endif

#	ifdef __DragonFly__
#		undef XIEITE_PLATFORM_DRAGONFLY
#		define XIEITE_PLATFORM_DRAGONFLY 1
#	endif

#	if defined(_SEQUENT_) || defined(sequent)
#		undef XIEITE_PLATFORM_DYNIX
#		define XIEITE_PLATFORM_DYNIX 1
#	endif

#	ifdef __ECOS
#		undef XIEITE_PLATFORM_ECOS
#		define XIEITE_PLATFORM_ECOS 1
#	endif

#	ifdef __EMX__
#		undef XIEITE_PLATFORM_EMX
#		define XIEITE_PLATFORM_EMX 1
#	endif

#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		undef XIEITE_PLATFORM_FREEBSD
#		define XIEITE_PLATFORM_FREEBSD 1
#	endif

#	if defined(__GNU__) || defined(__gnu_hurd__)
#		undef XIEITE_PLATFORM_GNU_HURD
#		define XIEITE_PLATFORM_GNU_HURD 1
#	endif

#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		undef XIEITE_PLATFORM_GNU_KFREEBSD
#		define XIEITE_PLATFORM_GNU_KFREEBSD 1
#	endif

#	ifdef __gnu_linux__
#		undef XIEITE_PLATFORM_GNU_LINUX
#		define XIEITE_PLATFORM_GNU_LINUX 1
#	endif

#	ifdef __hiuxmpp
#		undef XIEITE_PLATFORM_HI_UX_MPP
#		define XIEITE_PLATFORM_HI_UX_MPP 1
#	endif

#	ifdef __INTEGRITY
#		undef XIEITE_PLATFORM_INTEGRITY
#		define XIEITE_PLATFORM_INTEGRITY 1
#	endif

#	ifdef __INTERIX
#		undef XIEITE_PLATFORM_INTERIX
#		define XIEITE_PLATFORM_INTERIX 1
#	endif

#	if defined(sgi) || defined(__sgi)
#		undef XIEITE_PLATFORM_IRIX
#		define XIEITE_PLATFORM_IRIX 1
#	endif

#	ifdef __linux__
#		undef XIEITE_PLATFORM_LINUX
#		define XIEITE_PLATFORM_LINUX 1
#	endif

#	ifdef __Lynx__
#		undef XIEITE_PLATFORM_LYNXOS
#		define XIEITE_PLATFORM_LYNXOS 1
#	endif

#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		undef XIEITE_PLATFORM_MACINTOSH
#		define XIEITE_PLATFORM_MACINTOSH 1
#	endif

#	ifdef __minix
#		undef XIEITE_PLATFORM_MINIX
#		define XIEITE_PLATFORM_MINIX 1
#	endif

#	ifdef __MORPHOS__
#		undef XIEITE_PLATFORM_MORPHOS
#		define XIEITE_PLATFORM_MORPHOS 1
#	endif

#	if defined(mpeix) || defined(__mpexl)
#		undef XIEITE_PLATFORM_MPE_IX
#		define XIEITE_PLATFORM_MPE_IX 1
#	endif

#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		undef XIEITE_PLATFORM_MS_DOS
#		define XIEITE_PLATFORM_MS_DOS 1
#	endif

#	ifdef __NetBSD__
#		undef XIEITE_PLATFORM_NETBSD
#		define XIEITE_PLATFORM_NETBSD 1
#	endif

#	ifdef __TANDEM
#		undef XIEITE_PLATFORM_NONSTOP
#		define XIEITE_PLATFORM_NONSTOP 1
#	endif

#	ifdef __nucleus__
#		undef XIEITE_PLATFORM_NUCLEUS_RTOS
#		define XIEITE_PLATFORM_NUCLEUS_RTOS 1
#	endif

#	ifdef __OpenBSD__
#		undef XIEITE_PLATFORM_OPENBSD
#		define XIEITE_PLATFORM_OPENBSD 1
#	endif

#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		undef XIEITE_PLATFORM_OPENSERVER
#		define XIEITE_PLATFORM_OPENSERVER 1
#	endif

#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		undef XIEITE_PLATFORM_OS_2
#		define XIEITE_PLATFORM_OS_2 1
#	endif

#	ifdef __OS400__
#		undef XIEITE_PLATFORM_OS_400
#		define XIEITE_PLATFORM_OS_400 1
#	endif

#	if defined(__OS9000) || defined(_OSK)
#		undef XIEITE_PLATFORM_OS_9
#		define XIEITE_PLATFORM_OS_9 1
#	endif

#	ifdef __palmos__
#		undef XIEITE_PLATFORM_PALM_OS
#		define XIEITE_PLATFORM_PALM_OS 1
#	endif

#	ifdef EPLAN9
#		undef XIEITE_PLATFORM_PLAN_9
#		define XIEITE_PLATFORM_PLAN_9 1
#	endif

#	if defined(__QNX__) || defined(__QNXNTO__)
#		undef XIEITE_PLATFORM_QNX
#		define XIEITE_PLATFORM_QNX 1
#	endif

#	ifdef sinux
#		undef XIEITE_PLATFORM_SINIX
#		define XIEITE_PLATFORM_SINIX 1
#	endif

#	if defined(sun) || defined(__sun)
#		undef XIEITE_PLATFORM_SOLARIS
#		define XIEITE_PLATFORM_SOLARIS 1
#	endif

#	ifdef __SYGWIN__
#		undef XIEITE_PLATFORM_SYGWIN
#		define XIEITE_PLATFORM_SYGWIN 1
#	endif

#	ifdef __SYLLABLE__
#		undef XIEITE_PLATFORM_SYLLABLE
#		define XIEITE_PLATFORM_SYLLABLE 1
#	endif

#	ifdef __SYMBIAN32__
#		undef XIEITE_PLATFORM_SYMBIAN
#		define XIEITE_PLATFORM_SYMBIAN 1
#	endif

#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		undef XIEITE_PLATFORM_SYSTEM_V
#		define XIEITE_PLATFORM_SYSTEM_V 1
#	endif

#	if defined(__osf__) || defined(__osf)
#		undef XIEITE_PLATFORM_TRU64
#		define XIEITE_PLATFORM_TRU64 1
#	endif

#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		undef XIEITE_PLATFORM_ULTRIX
#		define XIEITE_PLATFORM_ULTRIX 1
#	endif

#	ifdef _UNICOS
#		undef XIEITE_PLATFORM_UNICOS
#		define XIEITE_PLATFORM_UNICOS 1
#	endif

#	if defined(_CRAY) || defined(__crayx1)
#		undef XIEITE_PLATFORM_UNICOS_MP
#		define XIEITE_PLATFORM_UNICOS_MP 1
#	endif

#	if defined(__unix__) || defined(__unix)
#		undef XIEITE_PLATFORM_UNIX
#		define XIEITE_PLATFORM_UNIX 1
#	endif

#	if defined(sco) || defined(_UNIXWARE7)
#		undef XIEITE_PLATFORM_UNIXWARE
#		define XIEITE_PLATFORM_UNIXWARE 1
#	endif

#	ifdef UTS
#		undef XIEITE_PLATFORM_UTS
#		define XIEITE_PLATFORM_UTS 1
#	endif

#	ifdef _UWIN
#		undef XIEITE_PLATFORM_UWIN
#		define XIEITE_PLATFORM_UWIN 1
#	endif

#	if defined(VMS) || defined(__VMS)
#		undef XIEITE_PLATFORM_VMS
#		define XIEITE_PLATFORM_VMS 1
#	endif

#	ifdef __VOS__
#		undef XIEITE_PLATFORM_VOS
#		define XIEITE_PLATFORM_VOS 1
#	endif

#	if defined(__VXWORKS__) || defined(__vxworks)
#		undef XIEITE_PLATFORM_VXWORKS
#		define XIEITE_PLATFORM_VXWORKS 1
#	endif

#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		undef XIEITE_PLATFORM_WINDOWS
#		define XIEITE_PLATFORM_WINDOWS 1
#	endif

#	ifdef _WIN32_WCE
#		undef XIEITE_PLATFORM_WINDOWS_CE
#		define XIEITE_PLATFORM_WINDOWS_CE 1
#	endif

#	ifdef _WINDU_SOURCE
#		undef XIEITE_PLATFORM_WIND_U
#		define XIEITE_PLATFORM_WIND_U 1
#	endif

#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		undef XIEITE_PLATFORM_Z_OS
#		define XIEITE_PLATFORM_Z_OS 1
#	endif

#endif
