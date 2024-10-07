# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:reverse\<\>\(\)
Defined in fragment [xieite:bits.reverse](../../../src/bits/reverse.cpp)

&nbsp;

## Description
Reverses the order of bits in an integer or `std::bitset`.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral reverse(Integral value) noexcept;
```
#### 2)
```cpp
template<std::size_t bits>
[[nodiscard]] constexpr std::bitset<bits> reverse(const std::bitset<bits>& values) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::bitset<8> foo = 0b11001010;

    std::println("{}", xieite::bits::reverse(foo).to_string());
}
```
Output:
```
01010011
```
