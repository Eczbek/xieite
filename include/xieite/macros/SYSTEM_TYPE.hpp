#ifndef XIEITE_HEADER_MACROS_SYSTEM_TYPE
#	define XIEITE_HEADER_MACROS_SYSTEM_TYPE

#	define XIEITE_SYSTEM_TYPE_AEGIS false
#	ifdef aegis
#		undef XIEITE_SYSTEM_TYPE_AEGIS
#		define XIEITE_SYSTEM_TYPE_AEGIS true
#	endif

#	define XIEITE_SYSTEM_TYPE_AIX false
#	ifdef _AIX
#		undef XIEITE_SYSTEM_TYPE_AIX
#		define XIEITE_SYSTEM_TYPE_AIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_AMIGAOS false
#	if defined(AMIGA) || defined(__amigaos__)
#		undef XIEITE_SYSTEM_TYPE_AMIGAOS
#		define XIEITE_SYSTEM_TYPE_AMIGAOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_ANDROID false
#	ifdef __ANDROID__
#		undef XIEITE_SYSTEM_TYPE_ANDROID
#		define XIEITE_SYSTEM_TYPE_ANDROID true
#	endif

#	define XIEITE_SYSTEM_TYPE_BEOS false
#	ifdef __BEOS__
#		undef XIEITE_SYSTEM_TYPE_BEOS
#		define XIEITE_SYSTEM_TYPE_BEOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_BLUE_GENE false
#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		undef XIEITE_SYSTEM_TYPE_BLUE_GENE
#		define XIEITE_SYSTEM_TYPE_BLUE_GENE true
#	endif

#	define XIEITE_SYSTEM_TYPE_BSD false
#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		undef XIEITE_SYSTEM_TYPE_BSD
#		define XIEITE_SYSTEM_TYPE_BSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_BSD_OS false
#	ifdef __bsdi__
#		undef XIEITE_SYSTEM_TYPE_BSD_OS
#		define XIEITE_SYSTEM_TYPE_BSD_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_CONVEXOS false
#	ifdef __convex__
#		undef XIEITE_SYSTEM_TYPE_CONVEXOS
#		define XIEITE_SYSTEM_TYPE_CONVEXOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_DC_OSX false
#	ifdef pyr
#		undef XIEITE_SYSTEM_TYPE_DC_OSX
#		define XIEITE_SYSTEM_TYPE_DC_OSX true
#	endif

#	define XIEITE_SYSTEM_TYPE_DG_UX false
#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		undef XIEITE_SYSTEM_TYPE_DG_UX
#		define XIEITE_SYSTEM_TYPE_DG_UX true
#	endif

#	define XIEITE_SYSTEM_TYPE_DOMAIN_OS false
#	ifdef apollo
#		undef XIEITE_SYSTEM_TYPE_DOMAIN_OS
#		define XIEITE_SYSTEM_TYPE_DOMAIN_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_DRAGONFLY false
#	ifdef __DragonFly__
#		undef XIEITE_SYSTEM_TYPE_DRAGONFLY
#		define XIEITE_SYSTEM_TYPE_DRAGONFLY true
#	endif

#	define XIEITE_SYSTEM_TYPE_DYNIX false
#	if defined(_SEQUENT_) || defined(sequent)
#		undef XIEITE_SYSTEM_TYPE_DYNIX
#		define XIEITE_SYSTEM_TYPE_DYNIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_ECOS false
#	ifdef __ECOS
#		undef XIEITE_SYSTEM_TYPE_ECOS
#		define XIEITE_SYSTEM_TYPE_ECOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_EMX false
#	ifdef __EMX__
#		undef XIEITE_SYSTEM_TYPE_EMX
#		define XIEITE_SYSTEM_TYPE_EMX true
#	endif

#	define XIEITE_SYSTEM_TYPE_FREEBSD false
#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		undef XIEITE_SYSTEM_TYPE_FREEBSD
#		define XIEITE_SYSTEM_TYPE_FREEBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_HURD false
#	if defined(__GNU__) || defined(__gnu_hurd__)
#		undef XIEITE_SYSTEM_TYPE_GNU_HURD
#		define XIEITE_SYSTEM_TYPE_GNU_HURD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD false
#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		undef XIEITE_SYSTEM_TYPE_GNU_KFREEBSD
#		define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_LINUX false
#	ifdef __gnu_linux__
#		undef XIEITE_SYSTEM_TYPE_GNU_LINUX
#		define XIEITE_SYSTEM_TYPE_GNU_LINUX true
#	endif

#	define XIEITE_SYSTEM_TYPE_HI_UX_MPP false
#	ifdef __hiuxmpp
#		undef XIEITE_SYSTEM_TYPE_HI_UX_MPP
#		define XIEITE_SYSTEM_TYPE_HI_UX_MPP true
#	endif

#	define XIEITE_SYSTEM_TYPE_INTEGRITY false
#	ifdef __INTEGRITY
#		undef XIEITE_SYSTEM_TYPE_INTEGRITY
#		define XIEITE_SYSTEM_TYPE_INTEGRITY true
#	endif

#	define XIEITE_SYSTEM_TYPE_INTERIX false
#	ifdef __INTERIX
#		undef XIEITE_SYSTEM_TYPE_INTERIX
#		define XIEITE_SYSTEM_TYPE_INTERIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_IRIX false
#	if defined(sgi) || defined(__sgi)
#		undef XIEITE_SYSTEM_TYPE_IRIX
#		define XIEITE_SYSTEM_TYPE_IRIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_LINUX false
#	ifdef __linux__
#		undef XIEITE_SYSTEM_TYPE_LINUX
#		define XIEITE_SYSTEM_TYPE_LINUX true
#	endif

#	define XIEITE_SYSTEM_TYPE_LYNXOS false
#	ifdef __Lynx__
#		undef XIEITE_SYSTEM_TYPE_LYNXOS
#		define XIEITE_SYSTEM_TYPE_LYNXOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MACOS false
#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		undef XIEITE_SYSTEM_TYPE_MACOS
#		define XIEITE_SYSTEM_TYPE_MACOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MINIX false
#	ifdef __minix
#		undef XIEITE_SYSTEM_TYPE_MINIX
#		define XIEITE_SYSTEM_TYPE_MINIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_MORPHOS false
#	ifdef __MORPHOS__
#		undef XIEITE_SYSTEM_TYPE_MORPHOS
#		define XIEITE_SYSTEM_TYPE_MORPHOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MPE_IX false
#	if defined(mpeix) || defined(__mpexl)
#		undef XIEITE_SYSTEM_TYPE_MPE_IX
#		define XIEITE_SYSTEM_TYPE_MPE_IX true
#	endif

#	define XIEITE_SYSTEM_TYPE_MS_DOS false
#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		undef XIEITE_SYSTEM_TYPE_MS_DOS
#		define XIEITE_SYSTEM_TYPE_MS_DOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_NETBSD false
#	ifdef __NetBSD__
#		undef XIEITE_SYSTEM_TYPE_NETBSD
#		define XIEITE_SYSTEM_TYPE_NETBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_NONSTOP false
#	ifdef __TANDEM
#		undef XIEITE_SYSTEM_TYPE_NONSTOP
#		define XIEITE_SYSTEM_TYPE_NONSTOP true
#	endif

#	define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS false
#	ifdef __nucleus__
#		undef XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS
#		define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_OPENBSD false
#	ifdef __OpenBSD__
#		undef XIEITE_SYSTEM_TYPE_OPENBSD
#		define XIEITE_SYSTEM_TYPE_OPENBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_OPENSERVER false
#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		undef XIEITE_SYSTEM_TYPE_OPENSERVER
#		define XIEITE_SYSTEM_TYPE_OPENSERVER true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_2 false
#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		undef XIEITE_SYSTEM_TYPE_OS_2
#		define XIEITE_SYSTEM_TYPE_OS_2 true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_400 false
#	ifdef __OS400__
#		undef XIEITE_SYSTEM_TYPE_OS_400
#		define XIEITE_SYSTEM_TYPE_OS_400 true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_9 false
#	if defined(__OS9000) || defined(_OSK)
#		undef XIEITE_SYSTEM_TYPE_OS_9
#		define XIEITE_SYSTEM_TYPE_OS_9 true
#	endif

#	define XIEITE_SYSTEM_TYPE_PALM_OS false
#	ifdef __palmos__
#		undef XIEITE_SYSTEM_TYPE_PALM_OS
#		define XIEITE_SYSTEM_TYPE_PALM_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_PLAN_9 false
#	ifdef EPLAN9
#		undef XIEITE_SYSTEM_TYPE_PLAN_9
#		define XIEITE_SYSTEM_TYPE_PLAN_9 true
#	endif

#	define XIEITE_SYSTEM_TYPE_QNX false
#	if defined(__QNX__) || defined(__QNXNTO__)
#		undef XIEITE_SYSTEM_TYPE_QNX
#		define XIEITE_SYSTEM_TYPE_QNX true
#	endif

#	define XIEITE_SYSTEM_TYPE_SINIX false
#	ifdef sinux
#		undef XIEITE_SYSTEM_TYPE_SINIX
#		define XIEITE_SYSTEM_TYPE_SINIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_SOLARIS false
#	if defined(sun) || defined(__sun)
#		undef XIEITE_SYSTEM_TYPE_SOLARIS
#		define XIEITE_SYSTEM_TYPE_SOLARIS true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYGWIN false
#	ifdef __SYGWIN__
#		undef XIEITE_SYSTEM_TYPE_SYGWIN
#		define XIEITE_SYSTEM_TYPE_SYGWIN true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYLLABLE false
#	ifdef __SYLLABLE__
#		undef XIEITE_SYSTEM_TYPE_SYLLABLE
#		define XIEITE_SYSTEM_TYPE_SYLLABLE true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYMBIAN false
#	ifdef __SYMBIAN32__
#		undef XIEITE_SYSTEM_TYPE_SYMBIAN
#		define XIEITE_SYSTEM_TYPE_SYMBIAN true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYSTEM_V false
#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		undef XIEITE_SYSTEM_TYPE_SYSTEM_V
#		define XIEITE_SYSTEM_TYPE_SYSTEM_V true
#	endif

#	define XIEITE_SYSTEM_TYPE_TRU64 false
#	if defined(__osf__) || defined(__osf)
#		undef XIEITE_SYSTEM_TYPE_TRU64
#		define XIEITE_SYSTEM_TYPE_TRU64 true
#	endif

#	define XIEITE_SYSTEM_TYPE_ULTRIX false
#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		undef XIEITE_SYSTEM_TYPE_ULTRIX
#		define XIEITE_SYSTEM_TYPE_ULTRIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNICOS false
#	ifdef _UNICOS
#		undef XIEITE_SYSTEM_TYPE_UNICOS
#		define XIEITE_SYSTEM_TYPE_UNICOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNICOS_MP false
#	if defined(_CRAY) || defined(__crayx1)
#		undef XIEITE_SYSTEM_TYPE_UNICOS_MP
#		define XIEITE_SYSTEM_TYPE_UNICOS_MP true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNIX false
#	if defined(__unix__) || defined(__unix)
#		undef XIEITE_SYSTEM_TYPE_UNIX
#		define XIEITE_SYSTEM_TYPE_UNIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNIXWARE false
#	if defined(sco) || defined(_UNIXWARE7)
#		undef XIEITE_SYSTEM_TYPE_UNIXWARE
#		define XIEITE_SYSTEM_TYPE_UNIXWARE true
#	endif

#	define XIEITE_SYSTEM_TYPE_UTS false
#	ifdef UTS
#		undef XIEITE_SYSTEM_TYPE_UTS
#		define XIEITE_SYSTEM_TYPE_UTS true
#	endif

#	define XIEITE_SYSTEM_TYPE_UWIN false
#	ifdef _UWIN
#		undef XIEITE_SYSTEM_TYPE_UWIN
#		define XIEITE_SYSTEM_TYPE_UWIN true
#	endif

#	define XIEITE_SYSTEM_TYPE_VMS false
#	if defined(VMS) || defined(__VMS)
#		undef XIEITE_SYSTEM_TYPE_VMS
#		define XIEITE_SYSTEM_TYPE_VMS true
#	endif

#	define XIEITE_SYSTEM_TYPE_VOS false
#	ifdef __VOS__
#		undef XIEITE_SYSTEM_TYPE_VOS
#		define XIEITE_SYSTEM_TYPE_VOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_VXWORKS false
#	if defined(__VXWORKS__) || defined(__vxworks)
#		undef XIEITE_SYSTEM_TYPE_VXWORKS
#		define XIEITE_SYSTEM_TYPE_VXWORKS true
#	endif

#	define XIEITE_SYSTEM_TYPE_WINDOWS false
#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		undef XIEITE_SYSTEM_TYPE_WINDOWS
#		define XIEITE_SYSTEM_TYPE_WINDOWS true
#	endif

#	define XIEITE_SYSTEM_TYPE_WINDOWS_CE false
#	ifdef _WIN32_WCE
#		undef XIEITE_SYSTEM_TYPE_WINDOWS_CE
#		define XIEITE_SYSTEM_TYPE_WINDOWS_CE true
#	endif

#	define XIEITE_SYSTEM_TYPE_WIND_U false
#	ifdef _WINDU_SOURCE
#		undef XIEITE_SYSTEM_TYPE_WIND_U
#		define XIEITE_SYSTEM_TYPE_WIND_U true
#	endif

#	define XIEITE_SYSTEM_TYPE_Z_OS false
#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		undef XIEITE_SYSTEM_TYPE_Z_OS
#		define XIEITE_SYSTEM_TYPE_Z_OS true
#	endif

#endif
