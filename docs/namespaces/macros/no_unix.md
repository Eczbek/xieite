# [XIEITE](../../macros.md)... \(No unix\)
Defined in header [<xieite/macros/no_unix.hpp>](../../../include/xieite/macros/no_unix.hpp)

&nbsp;

## Description
A header for removing the `unix` macro (if it exists), replacing it with `__unix` and `__unix__`. Intentionally lacks inclusion guards.

&nbsp;

## Synopsis
#### 1)
```cpp
#undef unix
```
#### 2)
```cpp
#define __unix 1
```
#### 3)
```cpp
#define __unix__ 1
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/no_unix.hpp"

int main() {
    int unix = 5;

    std::println("{}", unix);
}
```
Output:
```
5
```
