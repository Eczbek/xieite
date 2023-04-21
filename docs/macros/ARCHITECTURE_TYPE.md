# `XIEITE_ARCHITECTURE_TYPE_...`
Defined in header [`<xieite/macros/ARCHITECTURE_TYPE.hpp>`](../../include/xieite/macros/ARCHITECTURE_TYPE.hpp)

<br/>

Macros for identifying the current architecture type.

<br/><br/>

## Synopses

<br/>

```cpp
#if defined(i386) || defined(__i386) || defined(__i386__)
#	define XIEITE_ARCHITECTURE_TYPE_X86_32
#endif
```

<br/>

```cpp
#if defined(__amd64) || defined(__amd64__) || defined(__x86_64) || defined(__x86_64__)
#	undef XIEITE_ARCHITECTURE_TYPE_X86_32
#	define XIEITE_ARCHITECTURE_TYPE_X86_64
#endif
```

<br/>

```cpp
#if defined(__aarch64__)
#	define XIEITE_ARCHITECTURE_TYPE_ARM64
#endif
```
