# [XIEITE](../../macros.md)\_EAT\(\)
Defined in header [<xieite/eat.hpp>](../../../include/xieite/eat.hpp)

&nbsp;

## Description
A helper macro which consumes any number of expressions and expands to nothing.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_EAT(...)
```

&nbsp;

## Example
```cpp
#include <xieite/eat.hpp>

import std;

int main() {
    XIEITE_EAT(throw; std::terminate(); std::signal(SIGTERM));
    std::println("Hello, world!");
}
```
Output:
```
Hello, world!
```
