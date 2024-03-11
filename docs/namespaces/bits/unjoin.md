# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:unjoin\(\)
Defined in header [<xieite/bits/unjoin.hpp>](../../../include/xieite/bits/unjoin.hpp)

&nbsp;

## Description
Unjoins one `std::bitset` apart into multiple integers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral... Integers>
[[nodiscard]] constexpr std::tuple<Integers...> unjoin(const std::bitset<(... + xieite::types::sizeBits<Integers>)>& value) noexcept;
```
#### 2)
```cpp
template<std::integral Integer, std::size_t size>
[[nodiscard]] constexpr std::array<Integer, size> unjoin(const std::bitset<xieite::types::sizeBits<Integer> * size>& value) noexcept;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <print>
#include <tuple>
#include "xieite/bits/unjoin.hpp"

int main() {
    std::bitset<24> foo = 0b000001010000000011000111;
    auto bar = xieite::bits::unjoin<std::uint8_t, std::uint16_t>(foo);

    std::println("{}", std::get<0>(bar));
    std::println("{}", std::get<1>(bar));
}
```
Output:
```
5
199
```
