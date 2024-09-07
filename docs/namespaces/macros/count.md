# [XIEITE](../../macros.md)\_COUNT\(\)
Defined in header [<xieite/count.hpp>](../../../src/macros/count.hpp)

&nbsp;

## Description
Counts the number of arguments passed, up to 255.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_COUNT(...) /* natural integer */
```

&nbsp;

## Example
```cpp
#include <xieite/count.hpp>

import std;

int main() {
    std::println("{}", XIEITE_COUNT(a, b, c, d, e, f));
}
```
Output:
```
6
```
