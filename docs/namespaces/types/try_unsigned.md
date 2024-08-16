# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:TryUnsigned\<\>
Defined in header [<xieite/types/try_unsigned.hpp>](../../../include/xieite/types/try_unsigned.hpp)

&nbsp;

## Description
Attempts to get the unsigned complement of a signed type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type>
using TryUnsigned = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/try_signed.hpp"

int main() {
    std::println("{}", std::same_as<unsigned int, xieite::types::TryUnigned<int>>);
    std::println("{}", std::same_as<double, xieite::types::TryUnigned<double>>);
}
```
Possible output:
```
true
true
```
