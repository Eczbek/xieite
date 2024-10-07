# [XIEITE](../../macros.md)\_FORWARD\(\)
Defined in header [<xieite/forward.hpp>](../../../include/xieite/forward.hpp)

&nbsp;

## Description
A general utility for forwarding values. Includes a special case for avoiding unnecessarily materializing a temporary, like in `T x = XIEITE_FORWARD(T())`.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FORWARD(...) /* ... */
```

&nbsp;

## Example
```cpp
#include <xieite/forward.hpp>

import std;
import xieite;

template<typename T>
void foo(T&&) {
    std::println("{}", xieite::types::name<T>);
}

template<typename T>
void bar(T&& value) {
    foo(XIEITE_FORWARD(value));
}

int main() {
    bar(5);
}
```
Output:
```
int
```
