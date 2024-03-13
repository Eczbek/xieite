# [XIEITE](../../macros.md)\_EAT\(\)
Defined in header [<xieite/macros/eat.hpp>](../../../include/xieite/macros/eat.hpp)

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
#include <csignal>
#include <exception>
#include <print>
#include "xieite/macros/eat.hpp"

int main() {
    XIEITE_EAT(throw; std::terminate(); std::signal(SIGTERM));
    std::println("Hello, world!");
}
```
Output:
```
Hello, world!
```
