# [XIEITE](../macros.md)\_\_REPEAT\_CONCATENATE
Defined in header [<xieite/macros/REPEAT_CONCATENATE.hpp>](../../include/xieite/macros/REPEAT_CONCATENATE.hpp)

&nbsp;

## Description
Repeats the concatenation of an expression with itself.

&nbsp;

## Synopsis
```cpp
#define XIEITE__REPEAT_CONCATENATE(count, argument) XIEITE__LOOP(count, XIEITE_INTERNAL__REPEAT_CONCATENATE, , argument)
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/REPEAT_CONCATENATE.hpp>

int main() {
    std::cout << (XIEITE__REPEAT_CONCATENATE(3, 5) + 1) << '\n';
}
```
Output:
```
556
```
