# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:bigEndify\<\>\(\)
Defined in fragment [xieite:bits.bigEndify](../../../src/bits/big_endify.cpp)

&nbsp;

## Description
Byte-swaps an integer if the system is little-endian.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral>
[[nodiscard]] constexpr Integral bigEndify(Integral value) noexcept;
```

&nbsp;

## Example
```cpp
import std;
import xieite;

int main() {
    std::uint32_t foo = 12345;

    std::uint32_t bar = xieite::bits::bigEndify(foo);

    std::println("{}", std::bitset<32>(bar).to_string());
}
```
Output:
```
00111001001100000000000000000000
```
