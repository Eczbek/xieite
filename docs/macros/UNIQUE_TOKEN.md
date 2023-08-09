# [XIEITE](../macros.md)\_\_UNIQUE\_TOKEN
Defined in header [<xieite/macros/UNIQUE_TOKEN.hpp>](../../include/xieite/macros/UNIQUE_TOKEN.hpp)

&nbsp;

## Description
Creates a unique token.

&nbsp;

## Synopsis
```cpp
#define XIEITE__UNIQUE_TOKEN XIEITE__CONCATENATE(XIEITE_INTERNAL__UNIQUE_TOKEN_, __COUNTER__)
```

&nbsp;

## Example
```cpp
#include <xieite/macros/UNIQUE_TOKEN.hpp>

int main() {
    int XIEITE__UNIQUE_TOKEN = 999;

    double XIEITE__UNIQUE_TOKEN = 3.14159;
}
```
