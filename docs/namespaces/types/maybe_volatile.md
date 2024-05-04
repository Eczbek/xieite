# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatile\<\>
Defined in header [<xieite/types/maybe_volatile.hpp>](../../../include/xieite/types/maybe_volatile.hpp)

&nbsp;

## Description
An alias to an optionally volatile qualified type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, bool volatile_>
using MaybeVolatile = /* ... */;
```

&nbsp;

## Example
```cpp
#include <concepts>
#include <print>
#include "xieite/types/maybe_volatile.hpp"

int main() {
    std::println("{}", std::same_as<volatile int, xieite::types::MaybeVolatile<int, true>>);
    std::println("{}", std::same_as<int, xieite::types::MaybeVolatile<volatile int, false>>);
}
```
Output:
```
true
true
```
