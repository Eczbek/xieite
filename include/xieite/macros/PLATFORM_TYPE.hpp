#pragma once

#if defined(_WIN32) || defined(__WIN32__)
#	define XIEITE_PLATFORM_TYPE_WINDOWS_32
#endif

#if defined(_WIN64)
#	undef XIEITE_PLATFORM_TYPE_WINDOWS_32
#	define XIEITE_PLATFORM_TYPE_WINDOWS_64
#endif

#if defined(__APPLE_) && defined(__MACH__)
#	define XIEITE_PLATFORM_TYPE_MACOS
#endif

#if defined(__linux__)
#	define XIEITE_PLATFORM_TYPE_LINUX
#endif

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
#	define XIEITE_PLATFORM_TYPE_BSD
#endif
