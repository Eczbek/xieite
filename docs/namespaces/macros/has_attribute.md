# [XIEITE](../../macros.md)\_HAS\_ATTRIBUTE\(\)
Defined in header ["has_attribute.hpp"](../../../src/macros/has_attribute.hpp)

&nbsp;

## Description
Expands to a language-specific feature or compiler-specific extension to check if an attribute exists.

&nbsp;

## Synopsis
#### 1)
```cpp
#define XIEITE_HAS_ATTRIBUTE(...) /* boolean */
```

&nbsp;

## Example
```cpp
#include "has_attribute.hpp"

import std;

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
