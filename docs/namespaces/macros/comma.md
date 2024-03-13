# [XIEITE](../../macros.md)\_COMMA\(\)
Defined in header [<xieite/macros/comma.hpp>](../../../include/xieite/macros/comma.hpp)

&nbsp;

## Description
A helper macro which expands to a comma.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_COMMA(...) ,
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/comma.hpp"

int main() {
    std::println("{} {}", 3 XIEITE_COMMA() 4);
}
```
Output:
```
3 4
```
