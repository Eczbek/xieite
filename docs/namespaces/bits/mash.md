# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:mash\<\>\(\)
Defined in fragment [xieite:bits.mash](../../../src/bits/mash.cpp)

&nbsp;

## Description
"Mashes" multiple integers together into one `std::bitset`, allowing every value to have its own size.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::size_t... sizes, std::integral... Integrals>
[[nodiscard]] constexpr std::bitset<(... + sizes)> mash(Integrals... values) noexcept;
```
#### 2)
```cpp
template<std::size_t... sizes, std::integral Integral>
[[nodiscard]] constexpr std::bitset<(... + sizes)> mash(const std::array<Integral, sizeof...(sizes)>& values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint8_t foo = 0b101;
    std::uint16_t bar = 0b11000111;

    std::println("{}", xieite::bits::mash<3, 9>(foo, bar).to_string());
}
```
Output:
```
011000111101
```
