# [XIEITE](../../macros.md)\_DEBUG\_MODE
Defined in header [<xieite/macros/debug_mode.hpp>](../../../include/xieite/macros/debug_mode.hpp)

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
#include <print>
#include "xieite/macros/debug_mode.hpp"

int main() {
    std::println("{}", XIEITE_DEBUG_MODE);
}
```
Possible output:
```
0
```
