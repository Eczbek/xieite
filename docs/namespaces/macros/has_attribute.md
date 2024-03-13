# [XIEITE](../../macros.md)\_HAS\_ATTRIBUTE\(\)
Defined in header [<xieite/macros/has_attribute.hpp>](../../../include/xieite/macros/has_attribute.hpp)

&nbsp;

## Description
Expands to a language-specific feature or compiler-specific extension to check if an attribute exists.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_HAS_ATTRIBUTE(...) /* integer */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/has_attribute.hpp"

int main() {
    std::println("{}", XIEITE_HAS_ATTRIBUTE(nodiscard));
    std::println("{}", XIEITE_HAS_ATTRIBUTE(abcxyz));
}
```
Possible output:
```
201907
0
```
