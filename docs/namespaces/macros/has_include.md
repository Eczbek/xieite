# [XIEITE](../../macros.md)\_HAS\_INCLUDE\(\)
Defined in header [<xieite/macros/has_include.hpp>](../../../include/xieite/macros/has_include.hpp)

&nbsp;

## Description
Expands to a language-specific feature or compiler-specific extension to check if an inclusion exists.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_HAS_INCLUDE(...) /* boolean */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/has_include.hpp"

int main() {
    std::println("{}", XIEITE_HAS_INCLUDE(<cmath>));
    std::println("{}", XIEITE_HAS_INCLUDE(<abcxyz>));
}
```
Possible output:
```
1
0
```
