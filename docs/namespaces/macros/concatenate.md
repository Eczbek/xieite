# [XIEITE](../../macros.md)\_CONCATENATE
Defined in header [<xieite/macros/concatenate.hpp>](../../include/xieite/macros/concatenate.hpp)

&nbsp;

## Description
Concatenates expressions literally.

&nbsp;

## Synopsis
```cpp
#define XIEITE_CONCATENATE(first, second) /* ... */
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/concatenate.hpp>

int main() {
    std::cout << (XIEITE_CONCATENATE(4, 5) + 1) << '\n';
}
```
Output:
```
46
```
