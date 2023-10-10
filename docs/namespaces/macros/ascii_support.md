# [XIEITE](../../macros.md)\_ASCII\_SUPPORT
Defined in header [<xieite/macros/ascii_support.hpp>](../../include/xieite/macros/ascii_support.hpp)

&nbsp;

## Description
Checks if the compiler supports ASCII stuff. See header file for definition.

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/ascii_support.hpp>

int main() {
    std::cout
        << std::boolalpha
        << XIEITE_ASCII_SUPPORT << '\n';
}
```
Possible output:
```
true
```
