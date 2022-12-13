# XIEITE_COMPILER_TYPE
Declared in `<xieite/macros/COMPILER_TYPE.hpp>`

<br/>

Macros for identifying the current compiler type.

<br/><br/>

## Definitions
```cpp
#if defined(__GNUC__)
#	define XIEITE_COMPILER_TYPE_GCC
#endif
```
```cpp
#if defined(__clang__)
#	define XIEITE_COMPILER_TYPE_CLANG
#endif
```
```cpp
#if defined(__MINGW32__)
#	define XIEITE_COMPILER_TYPE_MINGW_32
#endif
```
```cpp
#if defined(__MINGW64__)
#	define XIEITE_COMPILER_TYPE_MINGW_64
#endif
```cpp
#if defined(_MSC_VER)
#	define XIEITE_COMPILER_TYPE_MSVC
#endif
```
