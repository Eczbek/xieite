# [xieite](../../../../xieite.md)\:\:[math](../../../../math.md)\:\:[literals](../../literals.md)\:\:base
Defined in header [<xieite/math/literals/base.hpp>](../../../../../include/xieite/math/literals/base.hpp)

&nbsp;

## Description
Useless.

&nbsp;

## Synopsis
#### 1)
```cpp
template<char... characters>
[[nodiscard]] constexpr int operator""_base() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/math/literals/base.hpp"

int main() {
    using namespace xieite::math::literals::base;

    std::cout
        << 111_base << '\n'
        << 011_base << '\n'
        << 0x1_base << '\n'
        << 0X1_base << '\n'
        << 0b1_base << '\n'
        << 0B1_base << '\n';
}
```
Output:
```
10
8
16
16
2
2
```
