# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatileData\<\>
Defined in header [<xieite/types/maybe_volatile_data.hpp>](../../../include/xieite/types/maybe_volatile_data.hpp)

&nbsp;

## Description
An alias to a pointer to an optionally volatile qualified data type, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Pointer Type, bool qualified>
using MaybeVolatileData = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/maybe_volatile_data.hpp"

int main() {
    std::println("{}", std::same_as<volatile int*, xieite::types::MaybeVolatileData<int*, true>>);
    std::println("{}", std::same_as<int*, xieite::types::MaybeVolatileData<volatile int*, false>>);
    std::println("{}", std::same_as<volatile int*&, xieite::types::MaybeVolatileData<int*&, true>>);
}
```
Output:
```
true
true
true
```
