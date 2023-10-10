# [XIEITE](../../macros.md)\_STRINGIFY
Defined in header [<xieite/macros/stringify.hpp>](../../../include/xieite/macros/stringify.hpp)

&nbsp;

## Description
Converts expressions to a string literally.

&nbsp;

## Synopsis
```cpp
#define XIEITE_STRINGIFY(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/stringify.hpp>

int main() {
    std::cout << XIEITE_STRINGIFY(2 + 2) << '\n';
}
```
Output:
```
2 + 2
```
