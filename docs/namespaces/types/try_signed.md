# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TrySigned\<\>
Defined in header [<xieite/types/try_signed.hpp>](../../../include/xieite/types/try_signed.hpp)

&nbsp;

## Description
Attempts to get the signed complement of an unsigned type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TrySigned = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/try_signed.hpp"

int main() {
    std::println("{}", std::same_as<int, xieite::types::TrySigned<unsigned int>>);
    std::println("{}", std::same_as<double, xieite::types::TrySigned<double>>);
}
```
Output:
```
true
true
```
