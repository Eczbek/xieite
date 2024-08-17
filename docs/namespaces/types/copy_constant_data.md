# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyConstantData\<\>
Defined in header [<xieite/types/copy_constant_data.hpp>](../../../include/xieite/types/copy_constant_data.hpp)

&nbsp;

## Description
Copies the constness of `Source` to the data type of `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, xieite::concepts::Pointer Target>
using CopyConstantData = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/copy_constant_data.hpp"

int main() {
    std::println("{}", std::same_as<const int*, xieite::types::CopyConstantData<const float, int*>>);
    std::println("{}", std::same_as<const int*&, xieite::types::CopyConstantData<const float, int*&>>);
}
```
Output:
```
true
true
```
