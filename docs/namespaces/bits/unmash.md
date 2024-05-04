# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:unmash\<\>\(\)
Defined in header [<xieite/bits/unmash.hpp>](../../../include/xieite/bits/unmash.hpp)

&nbsp;

## Description
"Unmashes" one `std::bitset` apart into multiple integers of specified sizes.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... sizes_>
[[nodiscard]] constexpr std::tuple<xieite::types::LeastInteger<sizes_>...> unmash(const std::bitset<(... + sizes_)>& value) noexcept;
```
#### 2)
```cpp
template<std::integral Integral_, std::size_t... sizes_>
[[nodiscard]] constexpr std::array<Integral_, sizeof...(sizes_)> unmash(const std::bitset<(... + sizes_)>& value) noexcept;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <print>
#include <tuple>
#include "xieite/bits/unmash.hpp"

int main() {
    std::bitset<12> foo = 0b101011000111;
    auto bar = xieite::bits::unmash<3, 9>(foo);

    std::println("{}", std::get<0>(bar));
    std::println("{}", std::get<1>(bar));
}
```
Output:
```
5
199
```
