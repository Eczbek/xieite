# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:join\<\>\(\)
Defined in header [<xieite/bits/join.hpp>](../../../include/xieite/bits/join.hpp)

&nbsp;

## Description
Joins multiple integers together into one `std::bitset`, preserving every values' full size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral... Integrals_>
[[nodiscard]] constexpr std::bitset<(... + xieite::types::sizeBits<Integrals_>)> join(Integrals_... values) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_, std::size_t size_>
[[nodiscard]] constexpr std::bitset<xieite::types::sizeBits<Integral_> * size_> join(const std::array<Integral_, size_>& values) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/bits/join.hpp"

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::println("{}", xieite::bits::join(foo, bar).to_string());
}
```
Output:
```
000001010000000011000111
```
