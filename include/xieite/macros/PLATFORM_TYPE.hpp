#pragma once

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__)
#	define XIEITE_PLATFORM_TYPE_WINDOWS
#elif defined(__APPLE_) && defined(__MACH__)
#	define XIEITE_PLATFORM_TYPE_MACOS
#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
#	define XIEITE_PLATFORM_TYPE_BSD
#elif defined(__linux__)
#	define XIEITE_PLATFORM_TYPE_LINUX
#endif
