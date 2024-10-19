# [XIEITE](../../macros.md)\_UNIX\_...
Defined in header [<xieite/unix.hpp>](../../../include/xieite/unix.hpp)

&nbsp;

## Description
Macros for identifying the current UNIX standard.

&nbsp;

## Synopsis
See header for definitions.

&nbsp;

## Example
```cpp
#include <xieite/unix_standard.hpp>

import std;

int main() {
#if XIEITE_UNIX_MAJOR_POSIX >= 2008
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
