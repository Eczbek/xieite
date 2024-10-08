# [XIEITE](../../macros.md)\_PLATFORM\_...
Defined in header [<xieite/platform.hpp>](../../../include/xieite/platform.hpp)

&nbsp;

## Description
Macros for identifying the current platform or operating system and its version (major, minor, patch).

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/platform.hpp>

import std;

int main() {
#if XIEITE_PLATFORM_TYPE_WINDOWS
    std::println("Windows");
#elif XIEITE_PLATFORM_TYPE_MACINTOSH
    std::println("Macintosh");
#elif XIEITE_PLATFORM_TYPE_LINUX
    std::println("Linux"); // :)
#else
    std::println("Other");
#endif
}
```
Possible output:
```
Linux
```
