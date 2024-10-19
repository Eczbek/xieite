# [XIEITE](../../macros.md)\_LIBRARY\_...
Defined in header [<xieite/library.hpp>](../../../include/xieite/library.hpp)

&nbsp;

## Description
Macros for identifying the current standard library its version (major, minor, patch).

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/library.hpp>

import std;

int main() {
#if XIEITE_LIBRARY_GNU_CPP
    std::println("GLIBC++");
#elif XIEITE_LIBRARY_LLVM_CPP
    std::println("LIBC++");
#else
    std::println("Other");
#endif
}
```
Possible output:
```
GLIBC++
```
