# [XIEITE](../../macros.md)\_DEBUG\_MODE
Defined in header [<xieite/debug_mode.hpp>](../../../src/macros/debug_mode.hpp)

&nbsp;

## Description
Detects whether a debug mode is active.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_DEBUG_MODE /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/debug_mode.hpp>

import std;

int main() {
    std::println("{}", XIEITE_DEBUG_MODE);
}
```
Possible output:
```
0
```
