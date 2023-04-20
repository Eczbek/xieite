# `XIEITE_PLATFORM_TYPE_...`
Defined in header [`<xieite/macros/PLATFORM_TYPE.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/macros/PLATFORM_TYPE.hpp)

<br/>

Macros for identifying the current platform type.

<br/><br/>

## Synopsis

<br/>

```cpp
#if defined(_WIN32) || defined(__WIN32__)
#	define XIEITE_PLATFORM_TYPE_WINDOWS_32
#endif
```

<br/>

```cpp
#if defined(_WIN64)
#	undef XIEITE_PLATFORM_TYPE_WINDOWS_32
#	define XIEITE_PLATFORM_TYPE_WINDOWS_64
#endif
```

<br/>

```cpp
#if defined(__APPLE_) && defined(__MACH__)
#	define XIEITE_PLATFORM_TYPE_MACOS
#endif
```

<br/>

```cpp
#if defined(__linux__)
#	define XIEITE_PLATFORM_TYPE_LINUX
#endif
```

<br/>

```cpp
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__bsdi__) || defined(__DragonFly__)
#	define XIEITE_PLATFORM_TYPE_BSD
#endif
```
