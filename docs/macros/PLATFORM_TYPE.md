# [`XIEITE`](../../docs/macros.md)`_PLATFORM_TYPE_...`
Defined in header [`<xieite/macros/PLATFORM_TYPE.hpp>`](../../include/xieite/macros/PLATFORM_TYPE.hpp)

<br/>

Macros for identifying the current platform type.

<br/><br/>

## Synopsis

<br/>

```cpp
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__)
#   define XIEITE_PLATFORM_TYPE_WINDOWS
#elif defined(__APPLE_) && defined(__MACH__)
#   define XIEITE_PLATFORM_TYPE_MACOS
#elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__)
#   define XIEITE_PLATFORM_TYPE_BSD
#elif defined(__linux__)
#   define XIEITE_PLATFORM_TYPE_LINUX
#endif
```
