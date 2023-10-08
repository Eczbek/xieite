# [XIEITE](../macros.md)\_\_SYSTEM\_TYPE\_\_...
Defined in header [<xieite/macros/SYSTEM_TYPE.hpp>](../../include/xieite/macros/SYSTEM_TYPE.hpp)

&nbsp;

## Description
Macros for identifying the current platform/OS. See header file for definitions.

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/SYSTEM_TYPE.hpp>

int main() {
#if XIEITE__SYSTEM_TYPE__WINDOWS
    std::cout << "Windows\n"; // trash
#elif XIEITE__SYSTEM_TYPE__MACINTOSH
    std::cout << "Macintosh\n"; // garbage
#elif XIEITE__SYSTEM_TYPE__LINUX
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
