# [XIEITE](../../macros.md)\_HAS\_DECLARE\_SPECIFIER\_ATTRIBUTE\(\)
Defined in header [<xieite/macros/has_declare_specifier_attribute.hpp>](../../../include/xieite/macros/has_declare_specifier_attribute.hpp)

&nbsp;

## Description
Expands to a compiler-specific extension to check if an attribute for `__declspec()` exists.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(...) /* boolean */
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/macros/has_declare_specifier_attribute.hpp"

int main() {
    std::println("{}", XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(dllexport));
    std::println("{}", XIEITE_HAS_DECLARE_SPECIFIER_ATTRIBUTE(abcxyz));
}
```
Possible output:
```
1
0
```
