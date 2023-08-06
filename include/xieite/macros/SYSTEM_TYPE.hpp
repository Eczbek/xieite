#ifndef XIEITE_HEADER__MACROS__SYSTEM__TYPE
#	define XIEITE_HEADER__MACROS__SYSTEM__TYPE

#	define XIEITE__SYSTEM_TYPE__AEGIS false
#	define XIEITE__SYSTEM_TYPE__AIX false
#	define XIEITE__SYSTEM_TYPE__AMIGAOS false
#	define XIEITE__SYSTEM_TYPE__ANDROID false
#	define XIEITE__SYSTEM_TYPE__BEOS false
#	define XIEITE__SYSTEM_TYPE__BLUE_GENE false
#	define XIEITE__SYSTEM_TYPE__BSD false
#	define XIEITE__SYSTEM_TYPE__BSD_OS false
#	define XIEITE__SYSTEM_TYPE__CONVEXOS false
#	define XIEITE__SYSTEM_TYPE__DC_OSX false
#	define XIEITE__SYSTEM_TYPE__DG_UX false
#	define XIEITE__SYSTEM_TYPE__DOMAIN_OS false
#	define XIEITE__SYSTEM_TYPE__DRAGONFLY false
#	define XIEITE__SYSTEM_TYPE__DYNIX false
#	define XIEITE__SYSTEM_TYPE__ECOS false
#	define XIEITE__SYSTEM_TYPE__EMX false
#	define XIEITE__SYSTEM_TYPE__FREEBSD false
#	define XIEITE__SYSTEM_TYPE__GNU_HURD false
#	define XIEITE__SYSTEM_TYPE__GNU_KFREEBSD false
#	define XIEITE__SYSTEM_TYPE__GNU_LINUX false
#	define XIEITE__SYSTEM_TYPE__HI_UX_MPP false
#	define XIEITE__SYSTEM_TYPE__INTEGRITY false
#	define XIEITE__SYSTEM_TYPE__INTERIX false
#	define XIEITE__SYSTEM_TYPE__IRIX false
#	define XIEITE__SYSTEM_TYPE__LINUX false
#	define XIEITE__SYSTEM_TYPE__LYNXOS false
#	define XIEITE__SYSTEM_TYPE__MACINTOSH false
#	define XIEITE__SYSTEM_TYPE__MINIX false
#	define XIEITE__SYSTEM_TYPE__MORPHOS false
#	define XIEITE__SYSTEM_TYPE__MPE_IX false
#	define XIEITE__SYSTEM_TYPE__MS_DOS false
#	define XIEITE__SYSTEM_TYPE__NETBSD false
#	define XIEITE__SYSTEM_TYPE__NONSTOP false
#	define XIEITE__SYSTEM_TYPE__NUCLEUS_RTOS false
#	define XIEITE__SYSTEM_TYPE__OPENBSD false
#	define XIEITE__SYSTEM_TYPE__OPENSERVER false
#	define XIEITE__SYSTEM_TYPE__OS_2 false
#	define XIEITE__SYSTEM_TYPE__OS_400 false
#	define XIEITE__SYSTEM_TYPE__OS_9 false
#	define XIEITE__SYSTEM_TYPE__PALM_OS false
#	define XIEITE__SYSTEM_TYPE__PLAN_9 false
#	define XIEITE__SYSTEM_TYPE__QNX false
#	define XIEITE__SYSTEM_TYPE__SINIX false
#	define XIEITE__SYSTEM_TYPE__SOLARIS false
#	define XIEITE__SYSTEM_TYPE__SYGWIN false
#	define XIEITE__SYSTEM_TYPE__SYLLABLE false
#	define XIEITE__SYSTEM_TYPE__SYMBIAN false
#	define XIEITE__SYSTEM_TYPE__SYSTEM_V false
#	define XIEITE__SYSTEM_TYPE__TRU64 false
#	define XIEITE__SYSTEM_TYPE__ULTRIX false
#	define XIEITE__SYSTEM_TYPE__UNICOS false
#	define XIEITE__SYSTEM_TYPE__UNICOS_MP false
#	define XIEITE__SYSTEM_TYPE__UNIX false
#	define XIEITE__SYSTEM_TYPE__UNIXWARE false
#	define XIEITE__SYSTEM_TYPE__UTS false
#	define XIEITE__SYSTEM_TYPE__UWIN false
#	define XIEITE__SYSTEM_TYPE__VMS false
#	define XIEITE__SYSTEM_TYPE__VOS false
#	define XIEITE__SYSTEM_TYPE__VXWORKS false
#	define XIEITE__SYSTEM_TYPE__WINDOWS false
#	define XIEITE__SYSTEM_TYPE__WINDOWS_CE false
#	define XIEITE__SYSTEM_TYPE__WIND_U false
#	define XIEITE__SYSTEM_TYPE__Z_OS false

#	ifdef aegis
#		undef XIEITE__SYSTEM_TYPE__AEGIS
#		define XIEITE__SYSTEM_TYPE__AEGIS true
#	endif

#	ifdef _AIX
#		undef XIEITE__SYSTEM_TYPE__AIX
#		define XIEITE__SYSTEM_TYPE__AIX true
#	endif

#	if defined(AMIGA) || defined(__amigaos__)
#		undef XIEITE__SYSTEM_TYPE__AMIGAOS
#		define XIEITE__SYSTEM_TYPE__AMIGAOS true
#	endif

#	ifdef __ANDROID__
#		undef XIEITE__SYSTEM_TYPE__ANDROID
#		define XIEITE__SYSTEM_TYPE__ANDROID true
#	endif

#	ifdef __BEOS__
#		undef XIEITE__SYSTEM_TYPE__BEOS
#		define XIEITE__SYSTEM_TYPE__BEOS true
#	endif

#	if defined(__bg__) || defined(__THW_BLUEGENE__)
#		undef XIEITE__SYSTEM_TYPE__BLUE_GENE
#		define XIEITE__SYSTEM_TYPE__BLUE_GENE true
#	endif

#	if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__) || defined(_SYSTYPE_BSD)
#		undef XIEITE__SYSTEM_TYPE__BSD
#		define XIEITE__SYSTEM_TYPE__BSD true
#	endif

#	ifdef __bsdi__
#		undef XIEITE__SYSTEM_TYPE__BSD_OS
#		define XIEITE__SYSTEM_TYPE__BSD_OS true
#	endif

#	ifdef __convex__
#		undef XIEITE__SYSTEM_TYPE__CONVEXOS
#		define XIEITE__SYSTEM_TYPE__CONVEXOS true
#	endif

#	ifdef pyr
#		undef XIEITE__SYSTEM_TYPE__DC_OSX
#		define XIEITE__SYSTEM_TYPE__DC_OSX true
#	endif

#	if defined(DGUX) || defined(__DGUX__) || defined(__dgux__)
#		undef XIEITE__SYSTEM_TYPE__DG_UX
#		define XIEITE__SYSTEM_TYPE__DG_UX true
#	endif

#	ifdef apollo
#		undef XIEITE__SYSTEM_TYPE__DOMAIN_OS
#		define XIEITE__SYSTEM_TYPE__DOMAIN_OS true
#	endif

#	ifdef __DragonFly__
#		undef XIEITE__SYSTEM_TYPE__DRAGONFLY
#		define XIEITE__SYSTEM_TYPE__DRAGONFLY true
#	endif

#	if defined(_SEQUENT_) || defined(sequent)
#		undef XIEITE__SYSTEM_TYPE__DYNIX
#		define XIEITE__SYSTEM_TYPE__DYNIX true
#	endif

#	ifdef __ECOS
#		undef XIEITE__SYSTEM_TYPE__ECOS
#		define XIEITE__SYSTEM_TYPE__ECOS true
#	endif

#	ifdef __EMX__
#		undef XIEITE__SYSTEM_TYPE__EMX
#		define XIEITE__SYSTEM_TYPE__EMX true
#	endif

#	if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#		undef XIEITE__SYSTEM_TYPE__FREEBSD
#		define XIEITE__SYSTEM_TYPE__FREEBSD true
#	endif

#	if defined(__GNU__) || defined(__gnu_hurd__)
#		undef XIEITE__SYSTEM_TYPE__GNU_HURD
#		define XIEITE__SYSTEM_TYPE__GNU_HURD true
#	endif

#	if defined(__FreeBSD_kernel__) && defined(__GLIBC__)
#		undef XIEITE__SYSTEM_TYPE__GNU_KFREEBSD
#		define XIEITE__SYSTEM_TYPE__GNU_KFREEBSD true
#	endif

#	ifdef __gnu_linux__
#		undef XIEITE__SYSTEM_TYPE__GNU_LINUX
#		define XIEITE__SYSTEM_TYPE__GNU_LINUX true
#	endif

#	ifdef __hiuxmpp
#		undef XIEITE__SYSTEM_TYPE__HI_UX_MPP
#		define XIEITE__SYSTEM_TYPE__HI_UX_MPP true
#	endif

#	ifdef __INTEGRITY
#		undef XIEITE__SYSTEM_TYPE__INTEGRITY
#		define XIEITE__SYSTEM_TYPE__INTEGRITY true
#	endif

#	ifdef __INTERIX
#		undef XIEITE__SYSTEM_TYPE__INTERIX
#		define XIEITE__SYSTEM_TYPE__INTERIX true
#	endif

#	if defined(sgi) || defined(__sgi)
#		undef XIEITE__SYSTEM_TYPE__IRIX
#		define XIEITE__SYSTEM_TYPE__IRIX true
#	endif

#	ifdef __linux__
#		undef XIEITE__SYSTEM_TYPE__LINUX
#		define XIEITE__SYSTEM_TYPE__LINUX true
#	endif

#	ifdef __Lynx__
#		undef XIEITE__SYSTEM_TYPE__LYNXOS
#		define XIEITE__SYSTEM_TYPE__LYNXOS true
#	endif

#	if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) && defined(__MACH__)
#		undef XIEITE__SYSTEM_TYPE__MACINTOSH
#		define XIEITE__SYSTEM_TYPE__MACINTOSH true
#	endif

#	ifdef __minix
#		undef XIEITE__SYSTEM_TYPE__MINIX
#		define XIEITE__SYSTEM_TYPE__MINIX true
#	endif

#	ifdef __MORPHOS__
#		undef XIEITE__SYSTEM_TYPE__MORPHOS
#		define XIEITE__SYSTEM_TYPE__MORPHOS true
#	endif

#	if defined(mpeix) || defined(__mpexl)
#		undef XIEITE__SYSTEM_TYPE__MPE_IX
#		define XIEITE__SYSTEM_TYPE__MPE_IX true
#	endif

#	if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#		undef XIEITE__SYSTEM_TYPE__MS_DOS
#		define XIEITE__SYSTEM_TYPE__MS_DOS true
#	endif

#	ifdef __NetBSD__
#		undef XIEITE__SYSTEM_TYPE__NETBSD
#		define XIEITE__SYSTEM_TYPE__NETBSD true
#	endif

#	ifdef __TANDEM
#		undef XIEITE__SYSTEM_TYPE__NONSTOP
#		define XIEITE__SYSTEM_TYPE__NONSTOP true
#	endif

#	ifdef __nucleus__
#		undef XIEITE__SYSTEM_TYPE__NUCLEUS_RTOS
#		define XIEITE__SYSTEM_TYPE__NUCLEUS_RTOS true
#	endif

#	ifdef __OpenBSD__
#		undef XIEITE__SYSTEM_TYPE__OPENBSD
#		define XIEITE__SYSTEM_TYPE__OPENBSD true
#	endif

#	if defined(M_I386) || defined(M_XENIX) || defined(_SCO_DS)
#		undef XIEITE__SYSTEM_TYPE__OPENSERVER
#		define XIEITE__SYSTEM_TYPE__OPENSERVER true
#	endif

#	if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__)
#		undef XIEITE__SYSTEM_TYPE__OS_2
#		define XIEITE__SYSTEM_TYPE__OS_2 true
#	endif

#	ifdef __OS400__
#		undef XIEITE__SYSTEM_TYPE__OS_400
#		define XIEITE__SYSTEM_TYPE__OS_400 true
#	endif

#	if defined(__OS9000) || defined(_OSK)
#		undef XIEITE__SYSTEM_TYPE__OS_9
#		define XIEITE__SYSTEM_TYPE__OS_9 true
#	endif

#	ifdef __palmos__
#		undef XIEITE__SYSTEM_TYPE__PALM_OS
#		define XIEITE__SYSTEM_TYPE__PALM_OS true
#	endif

#	ifdef EPLAN9
#		undef XIEITE__SYSTEM_TYPE__PLAN_9
#		define XIEITE__SYSTEM_TYPE__PLAN_9 true
#	endif

#	if defined(__QNX__) || defined(__QNXNTO__)
#		undef XIEITE__SYSTEM_TYPE__QNX
#		define XIEITE__SYSTEM_TYPE__QNX true
#	endif

#	ifdef sinux
#		undef XIEITE__SYSTEM_TYPE__SINIX
#		define XIEITE__SYSTEM_TYPE__SINIX true
#	endif

#	if defined(sun) || defined(__sun)
#		undef XIEITE__SYSTEM_TYPE__SOLARIS
#		define XIEITE__SYSTEM_TYPE__SOLARIS true
#	endif

#	ifdef __SYGWIN__
#		undef XIEITE__SYSTEM_TYPE__SYGWIN
#		define XIEITE__SYSTEM_TYPE__SYGWIN true
#	endif

#	ifdef __SYLLABLE__
#		undef XIEITE__SYSTEM_TYPE__SYLLABLE
#		define XIEITE__SYSTEM_TYPE__SYLLABLE true
#	endif

#	ifdef __SYMBIAN32__
#		undef XIEITE__SYSTEM_TYPE__SYMBIAN
#		define XIEITE__SYSTEM_TYPE__SYMBIAN true
#	endif

#	if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
#		undef XIEITE__SYSTEM_TYPE__SYSTEM_V
#		define XIEITE__SYSTEM_TYPE__SYSTEM_V true
#	endif

#	if defined(__osf__) || defined(__osf)
#		undef XIEITE__SYSTEM_TYPE__TRU64
#		define XIEITE__SYSTEM_TYPE__TRU64 true
#	endif

#	if defined(ultrix) || defined(__ultrix) || defined(__ultrix__) || defined(unix) && defined(vax)
#		undef XIEITE__SYSTEM_TYPE__ULTRIX
#		define XIEITE__SYSTEM_TYPE__ULTRIX true
#	endif

#	ifdef _UNICOS
#		undef XIEITE__SYSTEM_TYPE__UNICOS
#		define XIEITE__SYSTEM_TYPE__UNICOS true
#	endif

#	if defined(_CRAY) || defined(__crayx1)
#		undef XIEITE__SYSTEM_TYPE__UNICOS_MP
#		define XIEITE__SYSTEM_TYPE__UNICOS_MP true
#	endif

#	if defined(__unix__) || defined(__unix)
#		undef XIEITE__SYSTEM_TYPE__UNIX
#		define XIEITE__SYSTEM_TYPE__UNIX true
#	endif

#	if defined(sco) || defined(_UNIXWARE7)
#		undef XIEITE__SYSTEM_TYPE__UNIXWARE
#		define XIEITE__SYSTEM_TYPE__UNIXWARE true
#	endif

#	ifdef UTS
#		undef XIEITE__SYSTEM_TYPE__UTS
#		define XIEITE__SYSTEM_TYPE__UTS true
#	endif

#	ifdef _UWIN
#		undef XIEITE__SYSTEM_TYPE__UWIN
#		define XIEITE__SYSTEM_TYPE__UWIN true
#	endif

#	if defined(VMS) || defined(__VMS)
#		undef XIEITE__SYSTEM_TYPE__VMS
#		define XIEITE__SYSTEM_TYPE__VMS true
#	endif

#	ifdef __VOS__
#		undef XIEITE__SYSTEM_TYPE__VOS
#		define XIEITE__SYSTEM_TYPE__VOS true
#	endif

#	if defined(__VXWORKS__) || defined(__vxworks)
#		undef XIEITE__SYSTEM_TYPE__VXWORKS
#		define XIEITE__SYSTEM_TYPE__VXWORKS true
#	endif

#	if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
#		undef XIEITE__SYSTEM_TYPE__WINDOWS
#		define XIEITE__SYSTEM_TYPE__WINDOWS true
#	endif

#	ifdef _WIN32_WCE
#		undef XIEITE__SYSTEM_TYPE__WINDOWS_CE
#		define XIEITE__SYSTEM_TYPE__WINDOWS_CE true
#	endif

#	ifdef _WINDU_SOURCE
#		undef XIEITE__SYSTEM_TYPE__WIND_U
#		define XIEITE__SYSTEM_TYPE__WIND_U true
#	endif

#	if defined(__MVS__) || defined(__HOS_MVS__) || defined(__TOS_MVS__)
#		undef XIEITE__SYSTEM_TYPE__Z_OS
#		define XIEITE__SYSTEM_TYPE__Z_OS true
#	endif

#endif
