# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:xorShift\<\>\(\)
Defined in fragment [xieite:bits.xorShift](../../../src/bits/xor_shift.cpp)

&nbsp;

## Description
Performs a bitwise XOR operation on a value with itself shifted rightward.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral xorShift(Integral value, std::size_t bits) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint16_t foo = 0b1010101010101010;

    std::uint16_t bar = xieite::bits::xorShift(foo, 9);

    std::println("{}", std::bitset<16>(bar).toString());
}
```
Output:
```
1010101011111111
```
