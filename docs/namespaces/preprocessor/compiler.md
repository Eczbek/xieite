# [XIEITE](../../macros.md)\_COMPILER\_...
Defined in header [<xieite/compiler.hpp>](../../../include/xieite/compiler.hpp)

&nbsp;

## Description
Macros for identifying the current compiler type and version (major, minor, patch).

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/compiler.hpp>

import std;

int main() {
#if XIEITE_COMPILER_LEAST(GCC, 6, 39, 2000)
    std::println("yep");
#else
    std::println("nope");
#endif
}
```
Possible output:
```
yep
```
