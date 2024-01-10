# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:LeastInteger
Defined in header [<xieite/math/least_integer.hpp>](../../../include/xieite/math/least_integer.hpp)

&nbsp;

## Description
Determines the minimal unsigned integer type for any reasonable amount of bits.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t bits>
using LeastInteger = std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least8_t>, std::uint_least8_t, std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least16_t>, std::uint_least16_t, std::conditional_t<bits <= xieite::types::sizeBits<std::uint_least32_t>, std::uint_least32_t, std::uint_least64_t>>>;
```
