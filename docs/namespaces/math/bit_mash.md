# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:bitMash
Defined in header [<xieite/math/bit_mash.hpp>](../../../include/xieite/math/bit_mash.hpp)

&nbsp;

## Description
"Mashes" multiple integers together into one `std::bitset`, allowing every value to have its own size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... sizes, std::integral... Integers>
[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(Integers... values) noexcept;
```
#### 2)
```cpp
template<std::size_t... sizes, std::integral Integer>
[[nodiscard]] constexpr std::bitset<(... + sizes)> bitMash(const std::array<Integer, sizeof...(sizes)>& values) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include "xieite/math/bit_mash.hpp"

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::cout << xieite::math::bitMash<3, 9>(foo, bar) << '\n';
}
```
Output:
```
101011000111
```
