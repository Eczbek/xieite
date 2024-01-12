# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:bitJoin
Defined in header [<xieite/math/bit_join.hpp>](../../../include/xieite/math/bit_join.hpp)

&nbsp;

## Description
Joins multiple integers together into one `std::bitset`, preserving every values' full size.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral... Integers>
[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integers>)> bitJoin(Integers... values) noexcept;
```
#### 2)
```cpp
template<std::integral Integer, std::size_t size>
[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integer> * size> bitJoin(const std::array<Integer, size>& values) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/bit_join.hpp>

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::cout << xieite::math::bitJoin(foo, bar) << '\n';
}
```
Output:
```
000001010000000011000111
```
