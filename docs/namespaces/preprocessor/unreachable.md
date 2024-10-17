# [XIEITE](../../macros.md)\_UNREACHABLE\(\)
Defined in header [<xieite/unreachable.hpp>](../../../include/xieite/unreachable.hpp)

&nbsp;

## Description
Expands to `std::unreachable()` or a compiler-specific extension to emulate it.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_UNREACHABLE() /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/unreachable.hpp>

import std;

void foo(int x) {
    switch (x) {
    case 1:
        std::println("one");
        break;
    case 2:
        std::println("two");
        break;
    }
    XIEITE_UNREACHABLE();
}

int main() {
    foo(2);
}
```
Output:
```
two
```
