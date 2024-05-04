# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:xorShift\<\>\(\)
Defined in header [<xieite/bits/xor_shift.hpp>](../../../include/xieite/bits/xor_shift.hpp)

&nbsp;

## Description
Performs a bitwise XOR operation on a value with itself shifted rightward.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr Integral_ xorShift(Integral_ value, std::size_t bits) noexcept;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <print>
#include "xieite/bits/xor_shift.hpp"

int main() {
    std::uint16_t foo = 0b1010101010101010;

    std::uint16_t bar = xieite::bits::xorShift(foo, 9);

    std::println("{}", std::bitset<16>(bar).to_string());
}
```
Output:
```
1010101011111111
```
