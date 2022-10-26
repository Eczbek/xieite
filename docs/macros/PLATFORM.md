# GCUFL_PLATFORM
Declared in `<xieite/macros/PLATFORM.hpp>`
```cpp
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#	define GCUFL_PLATFORM_WINDOWS
#endif

#if defined(__unix__) || defined(__unix)
#	define GCUFL_PLATFORM_UNIX
#endif

#if defined(__APPLE_) && defined(__MACH__)
#	define GCUFL_PLATFORM_MACOS
#endif

#if defined(__linux__)
#	define GCUFL_PLATFORM_LINUX
#endif

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
#	define GCUFL_PLATFORM_BSD
#endif
```
Creates macros for the current platform.
