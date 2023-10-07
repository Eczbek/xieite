# [xieite](../xieite.md)\:\:[literals](../literals.md)\:\:\_base
Defined in header [<xieite/literals/base.hpp>](../../include/xieite/literals/base.hpp)

&nbsp;

## Description
Useless.

&nbsp;

## Synopses
#### 1)
```cpp
template<char... characters>
[[nodiscard]] constexpr int operator""_base() noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/literals/base.hpp>

int main() {
    using namespace xieite::literals;

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