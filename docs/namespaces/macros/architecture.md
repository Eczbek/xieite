# [XIEITE](../../macros.md)\_ARCHITECTURE\_...
Defined in header [<xieite/architecture.hpp>](../../../include/xieite/architecture.hpp)

&nbsp;

## Description
Macros for identifying the current architecture type and version (major, minor, patch).

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/architecture.hpp>

import std;

int main() {
#if XIEITE_ARCHITECTURE_VERSION_LEAST(MIPS, 4, 0, 0)
    std::println("yep");
#else
    std::println("nope");
#endif
}
```
Possible output:
```
nope
```
