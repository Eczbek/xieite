# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:bitUnmash
Defined in header [<xieite/math/bit_unmash.hpp>](../../../include/xieite/math/bit_unmash.hpp)

&nbsp;

## Description
"Unmashes" one `std::bitset` apart into multiple integers.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral... Integers>
[[nodiscard]] constexpr std::tuple<Integers...> bitUnmash(const std::bitset<(... + xieite::types::sizeBits<Integers>)>& bits) noexcept;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <xieite/math/bit_unmash.hpp>

int main() {
    std::bitset<24> foo = 0b000001010000000011000111;
    auto bar = xieite::math::bitUnmash<std::uint8_t, std::uint16_t>(foo);

    std::cout
        << static_cast<int>(std::get<0>(bar)) << '\n'
        << std::get<1>(bar) << '\n';
}
```
Output:
```
5
199
```
