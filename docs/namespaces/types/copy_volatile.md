# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CopyVolatile\<\>
Defined in header [<xieite/types/copy_volatile.hpp>](../../../include/xieite/types/copy_volatile.hpp)

&nbsp;

## Description
Copies the volatileness of `Source` to `Target`, disregarding reference qualifiers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Source, typename Target>
using CopyVolatile = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/copy_volatile.hpp"

int main() {
    std::println("{}", std::same_as<volatile int, xieite::types::CopyVolatile<volatile float, int>>);
    std::println("{}", std::same_as<volatile int&, xieite::types::CopyVolatile<volatile float, int&>>);
}
```
Output:
```
true
true
```
