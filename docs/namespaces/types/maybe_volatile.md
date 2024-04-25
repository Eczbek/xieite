# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:MaybeVolatile
Defined in header [<xieite/types/maybe_volatile.hpp>](../../../include/xieite/types/maybe_volatile.hpp)

&nbsp;

## Description
An alias to an optionally volatile qualified type.

&nbsp;

## Synopsis
#### 1)
```cpp
template<typename Type_, bool volatile_>
using MaybeVolatile = std::conditional_t<volatile_, std::add_volatile<Type_>, std::remove_volatile<Type_>>::type;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/types/maybe_volatile.hpp"
#include "xieite/types/name.hpp"

int main() {
    std::println("{}", xieite::types::name<xieite::types::MaybeVolatile<int, true>>);
    std::println("{}", xieite::types::name<xieite::types::MaybeVolatile<int, false>>);
}
```
Possible output:
```
volatile int
int
```
