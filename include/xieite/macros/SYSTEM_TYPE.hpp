#ifndef XIEITE_HEADER_MACROS_SYSTEM_TYPE
#	define XIEITE_HEADER_MACROS_SYSTEM_TYPE

#	define XIEITE_SYSTEM_TYPE_AEGIS false
#	define XIEITE_SYSTEM_TYPE_AIX false
#	define XIEITE_SYSTEM_TYPE_AMIGAOS false
#	define XIEITE_SYSTEM_TYPE_ANDROID false
#	define XIEITE_SYSTEM_TYPE_BEOS false
#	define XIEITE_SYSTEM_TYPE_BLUE_GENE false
#	define XIEITE_SYSTEM_TYPE_BSD false
#	define XIEITE_SYSTEM_TYPE_BSD_OS false
#	define XIEITE_SYSTEM_TYPE_CONVEXOS false
#	define XIEITE_SYSTEM_TYPE_DC_OSX false
#	define XIEITE_SYSTEM_TYPE_DG_UX false
#	define XIEITE_SYSTEM_TYPE_DOMAIN_OS false
#	define XIEITE_SYSTEM_TYPE_DRAGONFLY false
#	define XIEITE_SYSTEM_TYPE_DYNIX false
#	define XIEITE_SYSTEM_TYPE_ECOS false
#	define XIEITE_SYSTEM_TYPE_EMX false
#	define XIEITE_SYSTEM_TYPE_FREEBSD false
#	define XIEITE_SYSTEM_TYPE_GNU_HURD false
#	define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD false
#	define XIEITE_SYSTEM_TYPE_GNU_LINUX false
#	define XIEITE_SYSTEM_TYPE_HI_UX_MPP false
#	define XIEITE_SYSTEM_TYPE_INTEGRITY false
#	define XIEITE_SYSTEM_TYPE_INTERIX false
#	define XIEITE_SYSTEM_TYPE_IRIX false
#	define XIEITE_SYSTEM_TYPE_LINUX false
#	define XIEITE_SYSTEM_TYPE_LYNXOS false
#	define XIEITE_SYSTEM_TYPE_MACOS false
#	define XIEITE_SYSTEM_TYPE_MINIX false
#	define XIEITE_SYSTEM_TYPE_MORPHOS false
#	define XIEITE_SYSTEM_TYPE_MPE_IX false
#	define XIEITE_SYSTEM_TYPE_MS_DOS false
#	define XIEITE_SYSTEM_TYPE_NETBSD false
#	define XIEITE_SYSTEM_TYPE_NONSTOP false
#	define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS false
#	define XIEITE_SYSTEM_TYPE_OPENBSD false
#	define XIEITE_SYSTEM_TYPE_OPENSERVER false
#	define XIEITE_SYSTEM_TYPE_OS_2 false
#	define XIEITE_SYSTEM_TYPE_OS_400 false
#	define XIEITE_SYSTEM_TYPE_OS_9 false
#	define XIEITE_SYSTEM_TYPE_PALM_OS false
#	define XIEITE_SYSTEM_TYPE_PLAN_9 false
#	define XIEITE_SYSTEM_TYPE_QNX false
#	define XIEITE_SYSTEM_TYPE_SINIX false
#	define XIEITE_SYSTEM_TYPE_SOLARIS false
#	define XIEITE_SYSTEM_TYPE_SYGWIN false
#	define XIEITE_SYSTEM_TYPE_SYLLABLE false
#	define XIEITE_SYSTEM_TYPE_SYMBIAN false
#	define XIEITE_SYSTEM_TYPE_SYSTEM_V false
#	define XIEITE_SYSTEM_TYPE_TRU64 false
#	define XIEITE_SYSTEM_TYPE_ULTRIX false
#	define XIEITE_SYSTEM_TYPE_UNICOS false
#	define XIEITE_SYSTEM_TYPE_UNICOS_MP false
#	define XIEITE_SYSTEM_TYPE_UNIX false
#	define XIEITE_SYSTEM_TYPE_UNIXWARE false
#	define XIEITE_SYSTEM_TYPE_UTS false
#	define XIEITE_SYSTEM_TYPE_UWIN false
#	define XIEITE_SYSTEM_TYPE_VMS false
#	define XIEITE_SYSTEM_TYPE_VOS false
#	define XIEITE_SYSTEM_TYPE_VXWORKS false
#	define XIEITE_SYSTEM_TYPE_WINDOWS false
#	define XIEITE_SYSTEM_TYPE_WINDOWS_CE false
#	define XIEITE_SYSTEM_TYPE_WIND_U false
#	define XIEITE_SYSTEM_TYPE_Z_OS false

#	ifdef aegis
#		undef XIEITE_SYSTEM_TYPE_AEGIS
#		define XIEITE_SYSTEM_TYPE_AEGIS true
#	endif

#	ifdef _AIX
#		undef XIEITE_SYSTEM_TYPE_AIX
#		define XIEITE_SYSTEM_TYPE_AIX true
#	endif

#	if defined(AMIGA) || defined(__amigaos__)
#		undef XIEITE_SYSTEM_TYPE_AMIGAOS
#		define XIEITE_SYSTEM_TYPE_AMIGAOS true
#	endif

#	ifdef __ANDROID__
#		undef XIEITE_SYSTEM_TYPE_ANDROID
#		define XIEITE_SYSTEM_TYPE_ANDROID true
#	endif

#	ifdef __BEOS__
#		undef XIEITE_SYSTEM_TYPE_BEOS
#		define XIEITE_SYSTEM_TYPE_BEOS true
#	endif

#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		undef XIEITE_SYSTEM_TYPE_BLUE_GENE
#		define XIEITE_SYSTEM_TYPE_BLUE_GENE true
#	endif

#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		undef XIEITE_SYSTEM_TYPE_BSD
#		define XIEITE_SYSTEM_TYPE_BSD true
#	endif

#	ifdef __bsdi__
#		undef XIEITE_SYSTEM_TYPE_BSD_OS
#		define XIEITE_SYSTEM_TYPE_BSD_OS true
#	endif

#	ifdef __convex__
#		undef XIEITE_SYSTEM_TYPE_CONVEXOS
#		define XIEITE_SYSTEM_TYPE_CONVEXOS true
#	endif

#	ifdef pyr
#		undef XIEITE_SYSTEM_TYPE_DC_OSX
#		define XIEITE_SYSTEM_TYPE_DC_OSX true
#	endif

#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		undef XIEITE_SYSTEM_TYPE_DG_UX
#		define XIEITE_SYSTEM_TYPE_DG_UX true
#	endif

#	ifdef apollo
#		undef XIEITE_SYSTEM_TYPE_DOMAIN_OS
#		define XIEITE_SYSTEM_TYPE_DOMAIN_OS true
#	endif

#	ifdef __DragonFly__
#		undef XIEITE_SYSTEM_TYPE_DRAGONFLY
#		define XIEITE_SYSTEM_TYPE_DRAGONFLY true
#	endif

#	if defined(_SEQUENT_) || defined(sequent)
#		undef XIEITE_SYSTEM_TYPE_DYNIX
#		define XIEITE_SYSTEM_TYPE_DYNIX true
#	endif

#	ifdef __ECOS
#		undef XIEITE_SYSTEM_TYPE_ECOS
#		define XIEITE_SYSTEM_TYPE_ECOS true
#	endif

#	ifdef __EMX__
#		undef XIEITE_SYSTEM_TYPE_EMX
#		define XIEITE_SYSTEM_TYPE_EMX true
#	endif

#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		undef XIEITE_SYSTEM_TYPE_FREEBSD
#		define XIEITE_SYSTEM_TYPE_FREEBSD true
#	endif

#	if defined(__GNU__) || defined(__gnu_hurd__)
#		undef XIEITE_SYSTEM_TYPE_GNU_HURD
#		define XIEITE_SYSTEM_TYPE_GNU_HURD true
#	endif

#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		undef XIEITE_SYSTEM_TYPE_GNU_KFREEBSD
#		define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD true
#	endif

#	ifdef __gnu_linux__
#		undef XIEITE_SYSTEM_TYPE_GNU_LINUX
#		define XIEITE_SYSTEM_TYPE_GNU_LINUX true
#	endif

#	ifdef __hiuxmpp
#		undef XIEITE_SYSTEM_TYPE_HI_UX_MPP
#		define XIEITE_SYSTEM_TYPE_HI_UX_MPP true
#	endif

#	ifdef __INTEGRITY
#		undef XIEITE_SYSTEM_TYPE_INTEGRITY
#		define XIEITE_SYSTEM_TYPE_INTEGRITY true
#	endif

#	ifdef __INTERIX
#		undef XIEITE_SYSTEM_TYPE_INTERIX
#		define XIEITE_SYSTEM_TYPE_INTERIX true
#	endif

#	if defined(sgi) || defined(__sgi)
#		undef XIEITE_SYSTEM_TYPE_IRIX
#		define XIEITE_SYSTEM_TYPE_IRIX true
#	endif

#	ifdef __linux__
#		undef XIEITE_SYSTEM_TYPE_LINUX
#		define XIEITE_SYSTEM_TYPE_LINUX true
#	endif

#	ifdef __Lynx__
#		undef XIEITE_SYSTEM_TYPE_LYNXOS
#		define XIEITE_SYSTEM_TYPE_LYNXOS true
#	endif

#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		undef XIEITE_SYSTEM_TYPE_MACOS
#		define XIEITE_SYSTEM_TYPE_MACOS true
#	endif

#	ifdef __minix
#		undef XIEITE_SYSTEM_TYPE_MINIX
#		define XIEITE_SYSTEM_TYPE_MINIX true
#	endif

#	ifdef __MORPHOS__
#		undef XIEITE_SYSTEM_TYPE_MORPHOS
#		define XIEITE_SYSTEM_TYPE_MORPHOS true
#	endif

#	if defined(mpeix) || defined(__mpexl)
#		undef XIEITE_SYSTEM_TYPE_MPE_IX
#		define XIEITE_SYSTEM_TYPE_MPE_IX true
#	endif

#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		undef XIEITE_SYSTEM_TYPE_MS_DOS
#		define XIEITE_SYSTEM_TYPE_MS_DOS true
#	endif

#	ifdef __NetBSD__
#		undef XIEITE_SYSTEM_TYPE_NETBSD
#		define XIEITE_SYSTEM_TYPE_NETBSD true
#	endif

#	ifdef __TANDEM
#		undef XIEITE_SYSTEM_TYPE_NONSTOP
#		define XIEITE_SYSTEM_TYPE_NONSTOP true
#	endif

#	ifdef __nucleus__
#		undef XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS
#		define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS true
#	endif

#	ifdef __OpenBSD__
#		undef XIEITE_SYSTEM_TYPE_OPENBSD
#		define XIEITE_SYSTEM_TYPE_OPENBSD true
#	endif

#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		undef XIEITE_SYSTEM_TYPE_OPENSERVER
#		define XIEITE_SYSTEM_TYPE_OPENSERVER true
#	endif

#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		undef XIEITE_SYSTEM_TYPE_OS_2
#		define XIEITE_SYSTEM_TYPE_OS_2 true
#	endif

#	ifdef __OS400__
#		undef XIEITE_SYSTEM_TYPE_OS_400
#		define XIEITE_SYSTEM_TYPE_OS_400 true
#	endif

#	if defined(__OS9000) || defined(_OSK)
#		undef XIEITE_SYSTEM_TYPE_OS_9
#		define XIEITE_SYSTEM_TYPE_OS_9 true
#	endif

#	ifdef __palmos__
#		undef XIEITE_SYSTEM_TYPE_PALM_OS
#		define XIEITE_SYSTEM_TYPE_PALM_OS true
#	endif

#	ifdef EPLAN9
#		undef XIEITE_SYSTEM_TYPE_PLAN_9
#		define XIEITE_SYSTEM_TYPE_PLAN_9 true
#	endif

#	if defined(__QNX__) || defined(__QNXNTO__)
#		undef XIEITE_SYSTEM_TYPE_QNX
#		define XIEITE_SYSTEM_TYPE_QNX true
#	endif

#	ifdef sinux
#		undef XIEITE_SYSTEM_TYPE_SINIX
#		define XIEITE_SYSTEM_TYPE_SINIX true
#	endif

#	if defined(sun) || defined(__sun)
#		undef XIEITE_SYSTEM_TYPE_SOLARIS
#		define XIEITE_SYSTEM_TYPE_SOLARIS true
#	endif

#	ifdef __SYGWIN__
#		undef XIEITE_SYSTEM_TYPE_SYGWIN
#		define XIEITE_SYSTEM_TYPE_SYGWIN true
#	endif

#	ifdef __SYLLABLE__
#		undef XIEITE_SYSTEM_TYPE_SYLLABLE
#		define XIEITE_SYSTEM_TYPE_SYLLABLE true
#	endif

#	ifdef __SYMBIAN32__
#		undef XIEITE_SYSTEM_TYPE_SYMBIAN
#		define XIEITE_SYSTEM_TYPE_SYMBIAN true
#	endif

#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		undef XIEITE_SYSTEM_TYPE_SYSTEM_V
#		define XIEITE_SYSTEM_TYPE_SYSTEM_V true
#	endif

#	if defined(__osf__) || defined(__osf)
#		undef XIEITE_SYSTEM_TYPE_TRU64
#		define XIEITE_SYSTEM_TYPE_TRU64 true
#	endif

#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		undef XIEITE_SYSTEM_TYPE_ULTRIX
#		define XIEITE_SYSTEM_TYPE_ULTRIX true
#	endif

#	ifdef _UNICOS
#		undef XIEITE_SYSTEM_TYPE_UNICOS
#		define XIEITE_SYSTEM_TYPE_UNICOS true
#	endif

#	if defined(_CRAY) || defined(__crayx1)
#		undef XIEITE_SYSTEM_TYPE_UNICOS_MP
#		define XIEITE_SYSTEM_TYPE_UNICOS_MP true
#	endif

#	if defined(__unix__) || defined(__unix)
#		undef XIEITE_SYSTEM_TYPE_UNIX
#		define XIEITE_SYSTEM_TYPE_UNIX true
#	endif

#	if defined(sco) || defined(_UNIXWARE7)
#		undef XIEITE_SYSTEM_TYPE_UNIXWARE
#		define XIEITE_SYSTEM_TYPE_UNIXWARE true
#	endif

#	ifdef UTS
#		undef XIEITE_SYSTEM_TYPE_UTS
#		define XIEITE_SYSTEM_TYPE_UTS true
#	endif

#	ifdef _UWIN
#		undef XIEITE_SYSTEM_TYPE_UWIN
#		define XIEITE_SYSTEM_TYPE_UWIN true
#	endif

#	if defined(VMS) || defined(__VMS)
#		undef XIEITE_SYSTEM_TYPE_VMS
#		define XIEITE_SYSTEM_TYPE_VMS true
#	endif

#	ifdef __VOS__
#		undef XIEITE_SYSTEM_TYPE_VOS
#		define XIEITE_SYSTEM_TYPE_VOS true
#	endif

#	if defined(__VXWORKS__) || defined(__vxworks)
#		undef XIEITE_SYSTEM_TYPE_VXWORKS
#		define XIEITE_SYSTEM_TYPE_VXWORKS true
#	endif

#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		undef XIEITE_SYSTEM_TYPE_WINDOWS
#		define XIEITE_SYSTEM_TYPE_WINDOWS true
#	endif

#	ifdef _WIN32_WCE
#		undef XIEITE_SYSTEM_TYPE_WINDOWS_CE
#		define XIEITE_SYSTEM_TYPE_WINDOWS_CE true
#	endif

#	ifdef _WINDU_SOURCE
#		undef XIEITE_SYSTEM_TYPE_WIND_U
#		define XIEITE_SYSTEM_TYPE_WIND_U true
#	endif

#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		undef XIEITE_SYSTEM_TYPE_Z_OS
#		define XIEITE_SYSTEM_TYPE_Z_OS true
#	endif

#endif
