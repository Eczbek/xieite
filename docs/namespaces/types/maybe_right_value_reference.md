# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeLeftValueReference\<\>
Defined in header [<xieite/types/maybe_left_value_reference.hpp>](../../../include/xieite/types/maybe_left_value_reference.hpp)

&nbsp;

## Description
An alias to an optionally lvalue reference qualified type

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeLeftValueReference = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/maybe_left_value_reference.hpp"

int main() {
    std::println("{}", std::same_as<int&, xieite::types::MaybeLeftValueReference<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeLeftValueReference<int&, false>>);
}
```
Output:
```
true
true
```
