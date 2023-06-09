#ifndef XIEITE_HEADER_MACROS_SYSTEM_TYPE
#	define XIEITE_HEADER_MACROS_SYSTEM_TYPE

#	define XIEITE_SYSTEM_TYPE_AEGIS false
#	ifdef aegis
#		define XIEITE_SYSTEM_TYPE_AEGIS true
#	endif

#	define XIEITE_SYSTEM_TYPE_AIX false
#	ifdef _AIX
#		define XIEITE_SYSTEM_TYPE_AIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_AMIGAOS false
#	if defined(AMIGA) || defined(__amigaos__)
#		define XIEITE_SYSTEM_TYPE_AMIGAOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_ANDROID false
#	ifdef __ANDROID__
#		define XIEITE_SYSTEM_TYPE_ANDROID true
#	endif

#	define XIEITE_SYSTEM_TYPE_BEOS false
#	ifdef __BEOS__
#		define XIEITE_SYSTEM_TYPE_BEOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_BLUE_GENE false
#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		define XIEITE_SYSTEM_TYPE_BLUE_GENE true
#	endif

#	define XIEITE_SYSTEM_TYPE_BSD false
#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		define XIEITE_SYSTEM_TYPE_BSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_BSD_OS false
#	ifdef __bsdi__
#		define XIEITE_SYSTEM_TYPE_BSD_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_CONVEXOS false
#	ifdef __convex__
#		define XIEITE_SYSTEM_TYPE_CONVEXOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_DC_OSX false
#	ifdef pyr
#		define XIEITE_SYSTEM_TYPE_DC_OSX true
#	endif

#	define XIEITE_SYSTEM_TYPE_DG_UX false
#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		define XIEITE_SYSTEM_TYPE_DG_UX true
#	endif

#	define XIEITE_SYSTEM_TYPE_DOMAIN_OS false
#	ifdef apollo
#		define XIEITE_SYSTEM_TYPE_DOMAIN_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_DRAGONFLY false
#	ifdef __DragonFly__
#		define XIEITE_SYSTEM_TYPE_DRAGONFLY true
#	endif

#	define XIEITE_SYSTEM_TYPE_DYNIX false
#	if defined(_SEQUENT_) || defined(sequent)
#		define XIEITE_SYSTEM_TYPE_DYNIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_ECOS false
#	ifdef __ECOS
#		define XIEITE_SYSTEM_TYPE_ECOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_EMX false
#	ifdef __EMX__
#		define XIEITE_SYSTEM_TYPE_EMX true
#	endif

#	define XIEITE_SYSTEM_TYPE_FREEBSD false
#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		define XIEITE_SYSTEM_TYPE_FREEBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_HURD false
#	if defined(__GNU__) || defined(__gnu_hurd__)
#		define XIEITE_SYSTEM_TYPE_GNU_HURD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD false
#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		define XIEITE_SYSTEM_TYPE_GNU_KFREEBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_GNU_LINUX false
#	ifdef __gnu_linux__
#		define XIEITE_SYSTEM_TYPE_GNU_LINUX true
#	endif

#	define XIEITE_SYSTEM_TYPE_HI_UX_MPP false
#	ifdef __hiuxmpp
#		define XIEITE_SYSTEM_TYPE_HI_UX_MPP true
#	endif

#	define XIEITE_SYSTEM_TYPE_INTEGRITY false
#	ifdef __INTEGRITY
#		define XIEITE_SYSTEM_TYPE_INTEGRITY true
#	endif

#	define XIEITE_SYSTEM_TYPE_INTERIX false
#	ifdef __INTERIX
#		define XIEITE_SYSTEM_TYPE_INTERIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_IRIX false
#	if defined(sgi) || defined(__sgi)
#		define XIEITE_SYSTEM_TYPE_IRIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_LINUX false
#	ifdef __linux__
#		define XIEITE_SYSTEM_TYPE_LINUX true
#	endif

#	define XIEITE_SYSTEM_TYPE_LYNXOS false
#	ifdef __Lynx__
#		define XIEITE_SYSTEM_TYPE_LYNXOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MACOS false
#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		define XIEITE_SYSTEM_TYPE_MACOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MINIX false
#	ifdef __minix
#		define XIEITE_SYSTEM_TYPE_MINIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_MORPHOS false
#	ifdef __MORPHOS__
#		define XIEITE_SYSTEM_TYPE_MORPHOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_MPE_IX false
#	if defined(mpeix) || defined(__mpexl)
#		define XIEITE_SYSTEM_TYPE_MPE_IX true
#	endif

#	define XIEITE_SYSTEM_TYPE_MS_DOS false
#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		define XIEITE_SYSTEM_TYPE_MS_DOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_NETBSD false
#	ifdef __NetBSD__
#		define XIEITE_SYSTEM_TYPE_NETBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_NONSTOP false
#	ifdef __TANDEM
#		define XIEITE_SYSTEM_TYPE_NONSTOP true
#	endif

#	define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS false
#	ifdef __nucleus__
#		define XIEITE_SYSTEM_TYPE_NUCLEUS_RTOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_OPENBSD false
#	ifdef __OpenBSD__
#		define XIEITE_SYSTEM_TYPE_OPENBSD true
#	endif

#	define XIEITE_SYSTEM_TYPE_OPENSERVER false
#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		define XIEITE_SYSTEM_TYPE_OPENSERVER true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_2 false
#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		define XIEITE_SYSTEM_TYPE_OS_2 true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_400 false
#	ifdef __OS400__
#		define XIEITE_SYSTEM_TYPE_OS_400 true
#	endif

#	define XIEITE_SYSTEM_TYPE_OS_9 false
#	if defined(__OS9000) || defined(_OSK)
#		define XIEITE_SYSTEM_TYPE_OS_9 true
#	endif

#	define XIEITE_SYSTEM_TYPE_PALM_OS false
#	ifdef __palmos__
#		define XIEITE_SYSTEM_TYPE_PALM_OS true
#	endif

#	define XIEITE_SYSTEM_TYPE_PLAN_9 false
#	ifdef EPLAN9
#		define XIEITE_SYSTEM_TYPE_PLAN_9 true
#	endif

#	define XIEITE_SYSTEM_TYPE_QNX false
#	if defined(__QNX__) || defined(__QNXNTO__)
#		define XIEITE_SYSTEM_TYPE_QNX true
#	endif

#	define XIEITE_SYSTEM_TYPE_SINIX false
#	ifdef sinux
#		define XIEITE_SYSTEM_TYPE_SINIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_SOLARIS false
#	if defined(sun) || defined(__sun)
#		define XIEITE_SYSTEM_TYPE_SOLARIS true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYGWIN false
#	ifdef __SYGWIN__
#		define XIEITE_SYSTEM_TYPE_SYGWIN true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYLLABLE false
#	ifdef __SYLLABLE__
#		define XIEITE_SYSTEM_TYPE_SYLLABLE true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYMBIAN false
#	ifdef __SYMBIAN32__
#		define XIEITE_SYSTEM_TYPE_SYMBIAN true
#	endif

#	define XIEITE_SYSTEM_TYPE_SYSTEM_V false
#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		define XIEITE_SYSTEM_TYPE_SYSTEM_V true
#	endif

#	define XIEITE_SYSTEM_TYPE_TRU64 false
#	if defined(__osf__) || defined(__osf)
#		define XIEITE_SYSTEM_TYPE_TRU64 true
#	endif

#	define XIEITE_SYSTEM_TYPE_ULTRIX false
#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		define XIEITE_SYSTEM_TYPE_ULTRIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNICOS false
#	ifdef _UNICOS
#		define XIEITE_SYSTEM_TYPE_UNICOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNICOS_MP false
#	if defined(_CRAY) || defined(__crayx1)
#		define XIEITE_SYSTEM_TYPE_UNICOS_MP true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNIX false
#	if defined(__unix__) || defined(__unix)
#		define XIEITE_SYSTEM_TYPE_UNIX true
#	endif

#	define XIEITE_SYSTEM_TYPE_UNIXWARE false
#	if defined(sco) || defined(_UNIXWARE7)
#		define XIEITE_SYSTEM_TYPE_UNIXWARE true
#	endif

#	define XIEITE_SYSTEM_TYPE_UTS false
#	ifdef UTS
#		define XIEITE_SYSTEM_TYPE_UTS true
#	endif

#	define XIEITE_SYSTEM_TYPE_UWIN false
#	ifdef _UWIN
#		define XIEITE_SYSTEM_TYPE_UWIN true
#	endif

#	define XIEITE_SYSTEM_TYPE_VMS false
#	if defined(VMS) || defined(__VMS)
#		define XIEITE_SYSTEM_TYPE_VMS true
#	endif

#	define XIEITE_SYSTEM_TYPE_VOS false
#	ifdef __VOS__
#		define XIEITE_SYSTEM_TYPE_VOS true
#	endif

#	define XIEITE_SYSTEM_TYPE_VXWORKS false
#	if defined(__VXWORKS__) || defined(__vxworks)
#		define XIEITE_SYSTEM_TYPE_VXWORKS true
#	endif

#	define XIEITE_SYSTEM_TYPE_WINDOWS false
#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		define XIEITE_SYSTEM_TYPE_WINDOWS true
#	endif

#	define XIEITE_SYSTEM_TYPE_WINDOWS_CE false
#	ifdef _WIN32_WCE
#		define XIEITE_SYSTEM_TYPE_WINDOWS_CE true
#	endif

#	define XIEITE_SYSTEM_TYPE_WIND_U false
#	ifdef _WINDU_SOURCE
#		define XIEITE_SYSTEM_TYPE_WIND_U true
#	endif

#	define XIEITE_SYSTEM_TYPE_Z_OS false
#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		define XIEITE_SYSTEM_TYPE_Z_OS true
#	endif

#endif
