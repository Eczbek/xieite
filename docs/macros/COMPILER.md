# XIEITE_COMPILER_?
Declared in `<xieite/macros/COMPILER.hpp>`

<br/>

Macros for identifying the current compiler.

<br/><br/>

## Definitions
```cpp
#if defined(__GNUC__)
#	define XIEITE_COMPILER_GCC
#endif
```
```cpp
#if defined(__clang__)
#	define XIEITE_COMPILER_CLANG
#endif
```
```cpp
#if defined(__MINGW32__) || defined(__MINGW64__)
#	define XIEITE_COMPILER_MINGW
#endif
```
```cpp
#if defined(_MSC_VER)
#	define XIEITE_COMPILER_VISUAL_STUDIO
#endif
```
```cpp
#if defined(__EMSCRIPTEN__)
#	define XIEITE_COMPILER_EMSCRIPTEN
#endif
```
