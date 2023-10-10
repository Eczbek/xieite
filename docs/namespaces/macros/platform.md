# [XIEITE](../../macros.md)\_PLATFORM\_...
Defined in header [<xieite/macros/platform.hpp>](../../../include/xieite/macros/platform.hpp)

&nbsp;

## Description
Macros for identifying the current platform/OS. See header file for definitions.

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/platform.hpp>

int main() {
#if XIEITE_PLATFORM_WINDOWS
    std::cout << "Windows\n"; // trash
#elif XIEITE_PLATFORM_MACINTOSH
    std::cout << "Macintosh\n"; // garbage
#elif XIEITE_PLATFORM_LINUX
    std::cout << "Linux\n"; // #linuxmasterrace
#else
    std::cout << "Other\n"; // BSD?
#endif
}
```
Possible output:
```
Linux
```
