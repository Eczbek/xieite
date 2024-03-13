# [XIEITE](../../macros.md)\_UNUSED\(\)
Defined in header [<xieite/macros/unused.hpp>](../../../include/xieite/macros/unused.hpp)

&nbsp;

## Description
Used for avoiding warnings about unused parameters or statements without effect.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_UNUSED(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/unused.hpp"

void foo(int x, int y, int z) {
    std::println("X: {}, Z: {}", x, y);
    XIEITE_UNUSED(y);
}

int main() {
    foo(5, 10, 23);
}
```
Output:
```
X: 5, Z: 23
```
