# [XIEITE](../../macros.md)\_SCAN\(\)
Defined in header [<xieite/scan.hpp>](../../../include/xieite/scan.hpp)

&nbsp;

## Description
A helper macro which expands passed expressions.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_SCAN(...) __VA_ARGS__
```

&nbsp;

## Example
```cpp
#include <xieite/scan.md"
#include <xieite/stringify.md"

import std;

#define FOO() 17
#define BAR ()

int main() {
    std::println("{}", XIEITE_STRINGIFY(FOO BAR));
    std::println("{}", XIEITE_STRINGIFY(XIEITE_SCAN(FOO BAR)));
}
```
Output:
```
FOO ()
17
```
