# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:Fill \{\}
Defined in fragment [xieite:bits.Fill](../../../src/bits/fill.cpp)

&nbsp;

## Description
Fills something with specific bytes.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Fill {
    std::byte value;

    template<std::integral Integral>
    explicit constexpr Fill(Integral) noexcept;

    template<typename Type>
    explicit(false) constexpr operator Type() const noexcept;
};
```
- value
- [Fill\(\)](./structures/fill/1/operators/constructor.md)
- [operator typename\(\)](./structures/fill/1/operators/cast.md)

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint8_t x = xieite::bits::Fill(-1);
    std::uint16_t y = xieite::bits::Fill(-1);
    std::uint32_t x = xieite::bits::Fill(-1);

    std::println("{}", x);
    std::println("{}", y);
    std::println("{}", z);
};
```
Output:
```
255
65535
4294967295
```
