# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:mash\<\>\(\)
Defined in header [<xieite/bits/mash.hpp>](../../../include/xieite/bits/mash.hpp)

&nbsp;

## Description
"Mashes" multiple integers together into one `std::bitset`, allowing every value to have its own size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... sizes_, std::integral... Integrals_>
[[nodiscard]] constexpr std::bitset<(... + sizes_)> mash(Integrals_... values) noexcept;
```
#### 2)
```cpp
template<std::size_t... sizes_, std::integral Integral_>
[[nodiscard]] constexpr std::bitset<(... + sizes_)> mash(const std::array<Integral_, sizeof...(sizes_)>& values) noexcept;
```

&nbsp;

## Example
```cpp
#include <cstdint>
#include <print>
#include "xieite/bits/mash.hpp"

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::println("{}", xieite::bits::mash<3, 9>(foo, bar).to_string());
}
```
Output:
```
101011000111
```
