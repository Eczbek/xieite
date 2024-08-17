# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyVolatileData\<\>
Defined in header [<xieite/types/copy_volatile_data.hpp>](../../../include/xieite/types/copy_volatile_data.hpp)

&nbsp;

## Description
Copies the volatileness of `Source` to the data type of `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyVolatileData = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/copy_volatile_data.hpp"

int main() {
    std::println("{}", std::same_as<volatile int*, xieite::types::CopyVolatileData<volatile float, int*>>);
    std::println("{}", std::same_as<volatile int*&, xieite::types::CopyVolatileData<volatile float, int*&>>);
}
```
Output:
```
true
true
```
