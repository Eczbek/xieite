# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:reverse\<\>\(\)
Defined in header [<xieite/bits/reverse.hpp>](../../../include/xieite/bits/reverse.hpp)

&nbsp;

## Description
Reverses the order of bits in an integer or `std::bitset`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr Integral_ reverse(Integral_ value) noexcept;
```
#### 2)
```cpp
template<std::size_t bits_>
[[nodiscard]] constexpr std::bitset<bits_> reverse(const std::bitset<bits_>& values) noexcept;
```

&nbsp;

## Example
```cpp
#include <bit>
#include <print>
#include "xieite/bits/reverse.hpp"

int main() {
    std::bitset<8> foo = 0b11001010;

    std::println("{}", xieite::bits::reverse(foo).to_string());
}
```
Output:
```
01010011
```
