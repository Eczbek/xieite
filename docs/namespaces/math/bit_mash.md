# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:bitMash
Defined in header [<xieite/math/bit_mash.hpp>](../../../include/xieite/math/bit_mash.hpp)

&nbsp;

## Description
"Mashes" multiple integers together into one `std::bitset`.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::integral... Integers>
[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integers>)> bitMash(Integers... values) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <iostream>
#include <xieite/math/bit_mash.hpp>

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::cout << xieite::math::bitMash(foo, bar) << '\n';
}
```
Output:
```
000001010000000011000111
```
