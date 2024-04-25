# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeConstantData
Defined in header [<xieite/types/maybe_constant_data.hpp>](../../../include/xieite/types/maybe_constant_data.hpp)

&nbsp;

## Description
An alias to a pointer to an optionally constant qualified data type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, bool constant_>
requires(std::is_pointer_v<Type_> || std::is_reference_v<Type_>)
using MaybeConstantData = /* ... */;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_constant_data.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::MaybeConstantData<int*, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeConstantData<const int*, false>>);
}
```
Possible output:
```
const int*
int*
```
