# [xieite](../../xieite.md)\:\:[functors](../../functors.md)\:\:SignCast
Defined in header [<xieite/functors/sign_cast.hpp>](../../../include/xieite/functors/sign_cast.hpp)

&nbsp;

## Description
A functor which casts an integer to another integer's signedness before converting the value.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Target>
struct SignCast {
    template<std::integral Source>
    constexpr Target operator()(Source) noexcept;
};
```
##### Member functions
- [operator()](./structures/sign_cast/1/operators/call.md)

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/functors/sign_cast.hpp"

int main() {
    std::int8_t foo = -1;

    std::uint32_t bar = xieite::functors::SignCast<std::uint32_t>()(foo);

    std::println("{}", bar);
}
```
Output:
```
255
```
