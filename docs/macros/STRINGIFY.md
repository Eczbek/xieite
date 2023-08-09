# [XIEITE](../macros.md)\_\_STRINGIFY
Defined in header [<xieite/macros/STRINGIFY.hpp>](../../include/xieite/macros/STRINGIFY.hpp)

&nbsp;

## Description
Converts expressions to a string literally.

&nbsp;

## Synopsis
```cpp
#define XIEITE__STRINGIFY(...) XIEITE_INTERNAL__STRINGIFY(__VA_ARGS__)
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/STRINGIFY.hpp>

int main() {
    std::cout << XIEITE__STRINGIFY(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
