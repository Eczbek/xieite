# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatileData
Defined in header [<xieite/types/maybe_volatile_data.hpp>](../../../include/xieite/types/maybe_volatile_data.hpp)

&nbsp;

## Description
An alias to a pointer to an optionally volatile qualified data type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, bool volatile_>
requires(std::is_pointer_v<Type_> || std::is_reference_v<Type_>)
using MaybeVolatileData = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_volatile_data.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::MaybeVolatileData<int*, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeVolatileData<volatile int*, false>>);
}
```
Possible output:
```
volatile int*
int*
```
