# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:unjoin\<\>\(\)
Defined in header [<xieite/bits/unjoin.hpp>](../../../include/xieite/bits/unjoin.hpp)

&nbsp;

## Description
Unjoins one `std::bitset` apart into multiple integers.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral... Integrals, std::size_t bits>
requires(bits >= (... + xieite::bits::size<Integrals>))
[[nodiscard]] constexpr std::tuple<Integrals...> unjoin(std::bitset<bits> value) noexcept;
```
#### 2)
```cpp
template<std::integral Integral, std::size_t size, std::size_t bits>
requires(bits >= (xieite::bits::size<Integral> * size))
[[nodiscard]] constexpr std::array<Integral, size> unjoin(std::bitset<bits> value) noexcept;
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
    std::bitset<24> foo = 0b000000001100011100000101;
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
