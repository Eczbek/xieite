# [XIEITE](../../macros.md)\_REPEAT\_CONCATENATE
Defined in header [<xieite/macros/repeat_concatenate.hpp>](../../../include/xieite/macros/repeat_concatenate.hpp)

&nbsp;

## Description
Repeats the concatenation of an expression with itself.

&nbsp;

## Synopsis
```cpp
#define XIEITE_REPEAT_CONCATENATE(count, argument) XIEITE_LOOP(count, XIEITE_INTERNAL_REPEAT_CONCATENATE, , argument)
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/macros/repeat_concatenate.hpp>

int main() {
    std::cout << (XIEITE_REPEAT_CONCATENATE(3, 5) + 1) << '\n';
}
```
Output:
```
556
```
