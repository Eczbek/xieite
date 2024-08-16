# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatileData\<\>
Defined in header [<xieite/types/maybe_volatile_data.hpp>](../../../include/xieite/types/maybe_volatile_data.hpp)

&nbsp;

## Description
An alias to a pointer to an optionally volatile qualified data type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type, bool volatileQualified>
requires(std::is_pointer_v<Type> || std::is_reference_v<Type>)
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
}
```
Output:
```
true
true
```
