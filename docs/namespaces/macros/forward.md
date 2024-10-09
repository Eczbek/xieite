# [XIEITE](../../macros.md)\_FORWARD\(\)
Defined in header [<xieite/forward.hpp>](../../../include/xieite/forward.hpp)

&nbsp;

## Description
A terrible (improved) replacement for `std::forward`.

Includes special cases:  
\- Avoids unnecessarily materializing a temporary: `T x = XIEITE_FORWARD(T())`  
\- Does nothing for a prvalue lambda argument: `XIEITE_FORWARD([] {})`  
\- Does nothing for a prvalue void argument: `XIEITE_FORWARD(void())`

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
