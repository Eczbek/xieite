# XIEITE_PLATFORM_TYPE
Declared in `<xieite/macros/PLATFORM_TYPE.hpp>`

<br/>

Macros for identifying the current platform type.

<br/><br/>

## Definitions
```cpp
#if defined(_WIN32) || defined(__WIN32__)
#	define XIEITE_PLATFORM_TYPE_WINDOWS_32
#endif
```
```cpp
#if defined(_WIN64)
#	undef XIEITE_PLATFORM_TYPE_WINDOWS_32
#	define XIEITE_PLATFORM_TYPE_WINDOWS_64
#endif
```
```cpp
#if defined(__APPLE_) && defined(__MACH__)
#	define XIEITE_PLATFORM_TYPE_MACOS
#endif
```
```cpp
#if defined(__linux__)
#	define XIEITE_PLATFORM_TYPE_LINUX
#endif
```
```cpp
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
#	define XIEITE_PLATFORM_TYPE_BSD
#endif
```
