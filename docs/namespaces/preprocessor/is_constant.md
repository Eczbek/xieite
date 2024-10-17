# [XIEITE](../../macros.md)\_IS\_CONSTANT\(\)
Defined in header [<xieite/is_constant.hpp>](../../../include/xieite/is_constant.hpp)

&nbsp;

## Description
Expands to a call to `__builtin_constant_p` on GCC and Clang, or `0` on MSVC.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_IS_CONSTANT(...) /* boolean */
```

&nbsp;

## Example
```cpp
#include <xieite/is_constant.hpp>

import std;

constexpr void foo() {}
void bar() {}

int main() {
    std::println("{}", XIEITE_IS_CONSTANT(foo()));
    std::println("{}", XIEITE_IS_CONSTANT(bar()));
}
```
Possible output:
```
1
0
```
