# [XIEITE](../../macros.md)\_\_REPEAT\_CONCATENATE
Defined in header [<xieite/macros/repeat_concatenate.hpp>](../../include/xieite/macros/repeat_concatenate.hpp)

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
#include <xieite/macros/repeat_concatenate.hpp>

int main() {
    std::cout << (XIEITE__REPEAT_CONCATENATE(3, 5) + 1) << '\n';
}
```
Output:
```
556
```
