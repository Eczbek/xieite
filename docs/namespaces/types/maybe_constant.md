# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstant\<\>
Defined in header [<xieite/types/maybe_constant.hpp>](../../../include/xieite/types/maybe_constant.hpp)

&nbsp;

## Description
An alias to an optionally constant qualified type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool constantQualified>
using MaybeConstant = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/maybe_constant.hpp"

int main() {
    std::println("{}", std::same_as<const int, xieite::types::MaybeConstant<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeConstant<const int, false>>);
}
```
Output:
```
true
true
```
