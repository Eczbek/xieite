# [XIEITE](../../macros.md)\_COMMA\(\)
Defined in header [<xieite/comma.hpp>](../../../src/macros/comma.hpp)

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
#include <xieite/comma.hpp>

import std;

int main() {
    std::println("{} {}", 3 XIEITE_COMMA() 4);
}
```
Output:
```
3 4
```
