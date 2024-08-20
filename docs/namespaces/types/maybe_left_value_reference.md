# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeRightValueReference\<\>
Defined in header [<xieite/types/maybe_right_value_reference.hpp>](../../../include/xieite/types/maybe_right_value_reference.hpp)

&nbsp;

## Description
An alias to an optionally rvalue reference qualified type

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool qualified>
using MaybeRightValueReference = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/maybe_right_value_reference.hpp"

int main() {
    std::println("{}", std::same_as<int&&, xieite::types::MaybeRightValueReference<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeRightValueReference<int&&, false>>);
}
```
Output:
```
true
true
```
