# [XIEITE](../macros.md)\_ASCII\_SUPPORT
Defined in header [<xieite/macros/ASCII_SUPPORT.hpp>](../../include/xieite/macros/ASCII_SUPPORT.hpp)

&nbsp;

## Description
Checks if the compiler supports ASCII stuff. See header file for definition

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/ASCII_SUPPORT.hpp>

int main() {
    std::cout
        << std::boolalpha
        << XIEITE__ASCII_SUPPORT << '\n';
}
```
Possible output:
```
true
```
