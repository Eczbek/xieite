# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyConstant\<\>
Defined in header [<xieite/types/copy_constant.hpp>](../../../include/xieite/types/copy_constant.hpp)

&nbsp;

## Description
Copies the constness of `Source` to `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyConstant = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/copy_constant.hpp"

int main() {
    std::println("{}", std::same_as<const int, xieite::types::CopyConstant<const float, int>>);
    std::println("{}", std::same_as<const int&, xieite::types::CopyConstant<const float, int&>>);
}
```
Output:
```
true
true
```
