# [XIEITE](../../macros.md)\_FORWARD\(\)
Defined in header [<xieite/forward.hpp>](../../../include/xieite/forward.hpp)

&nbsp;

## Description
A (terrible) replacement for `std::forward`. See definition.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_FORWARD(...) /* ... */
```
Includes special cases:  
\- Avoids unnecessarily materializing a temporary: `T x = XIEITE_FORWARD(T())`  
\- Does nothing for a prvalue lambda argument: `XIEITE_FORWARD([] {})`  
\- Does nothing for a prvalue void argument: `XIEITE_FORWARD(void())`

&nbsp;

## Example
```cpp
#include <xieite/forward.hpp>

import std;
import xieite;

void foo(int&&) {
    std::print("Done\n");
}

void bar(auto&& value) {
    foo(XIEITE_FORWARD(value));
}

int main() {
    bar(5);
}
```
Possible output:
```
Done
```
