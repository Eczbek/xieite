# [XIEITE](../macros.md)\_\_CONCATENATE
Defined in header [<xieite/macros/CONCATENATE.hpp>](../../include/xieite/macros/CONCATENATE.hpp)

&nbsp;

## Description
Concatenates expressions literally.

&nbsp;

## Synopsis
```cpp
#define XIEITE__CONCATENATE(first, second) XIEITE_INTERNAL__CONCATENATE(first, second)
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/CONCATENATE.hpp>

int main() {
    std::cout << (XIEITE__CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
