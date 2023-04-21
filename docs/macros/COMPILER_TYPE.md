# [`XIEITE`](../../docs/macros.md)`_COMPILER_TYPE_...`
Defined in header [`<xieite/macros/COMPILER_TYPE.hpp>`](../../include/xieite/macros/COMPILER_TYPE.hpp)

<br/>

Macros for identifying the current compiler type.

<br/><br/>

## Synopses

<br/>

```cpp
#if defined(__GNUC__)
#	define XIEITE_COMPILER_TYPE_GCC
#endif
```

<br/>

```cpp
#if defined(__clang__)
#	define XIEITE_COMPILER_TYPE_CLANG
#endif
```

<br/>

```cpp
#if defined(__MINGW32__)
#	define XIEITE_COMPILER_TYPE_MINGW_32
#endif
```

<br/>

```cpp
#if defined(__MINGW64__)
#	define XIEITE_COMPILER_TYPE_MINGW_64
#endif
```

<br/>

```cpp
#if defined(_MSC_VER)
#	define XIEITE_COMPILER_TYPE_MSVC
#endif
```
