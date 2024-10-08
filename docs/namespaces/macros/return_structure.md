# [XIEITE](../../macros.md)\_RETURN\_STRUCTURE\(\)
Defined in header [<xieite/return_structure.hpp>](../../../include/xieite/return_structure.hpp)

&nbsp;

## Description
Allows returning a temporary structure without naming it yourself. Uses `__COUNTER__` internally.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_RETURN_STRUCTURE(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/return_structure.hpp>

import std;

auto foo() {
    XIEITE_RETURN_STRUCTURE({
        int x;
        int y;
    }) {
        .x = 1,
        .y = 2
    };
}

int main() {
    auto [x, y] = foo();
    std::print("{} {}\n", x, y);
```
Output:
```
1 2
```
