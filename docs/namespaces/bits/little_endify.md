# [xieite](../../xieite.md)\:\:[bits](../../bits.md)\:\:littleEndify\<\>\(\)
Defined in header [<xieite/bits/little_endify.hpp>](../../../include/xieite/bits/little_endify.hpp)

&nbsp;

## Description
Byte-swaps an integer if the system is little-endian.

&nbsp;

## Synopsis
#### 1)
```cpp
template<std::integral Integral_>
[[nodiscard]] constexpr Integral_ littleEndify(Integral_ value) noexcept;
```

&nbsp;

## Example
```cpp
#include <bitset>
#include <cstdint>
#include <print>
#include "xieite/bits/little_endify.hpp"

int main() {
    std::uint32_t foo = 12345;

    std::uint32_t bar = xieite::bits::littleEndify(foo);

    std::println("{}", std::bitset<32>(bar).to_string());
}
```
Output:
```
00000000000000000011000000111001
```
