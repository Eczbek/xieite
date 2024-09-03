# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:join\<\>\(\)
Defined in fragment [xieite:bits.join](../../../src/bits/join.cpp)

&nbsp;

## Description
Joins multiple integers together into one `std::bitset`, preserving every values' full size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral... Integrals>
[[nodiscard]] constexpr std::bitset<(... + xieite::bits::size<Integrals>)> join(Integrals... values) noexcept;
```
#### 2)
```cpp
template<std::integral Integral, std::size_t size>
[[nodiscard]] constexpr std::bitset<xieite::bits::size<Integral> * size> join(const std::array<Integral, size>& values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::println("{}", xieite::bits::join(foo, bar).toString());
}
```
Output:
```
000000001100011100000101
```
