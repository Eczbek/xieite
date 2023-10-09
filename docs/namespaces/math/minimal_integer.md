# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:MinimalInteger
Defined in header [<xieite/math/minimal_integer.hpp>](../../../include/xieite/math/minimal_integer.hpp)

&nbsp;

## Description
Determines the minimal unsigned integer type for any reasonable amount of bits.

&nbsp;

## Synopses
#### 1)
```cpp
template<std::size_t bits>
using MinimalInteger = std::conditional_t<bits <= std::numeric_limits<std::uint8_t>::digits, std::uint8_t, std::conditional_t<bits <= std::numeric_limits<std::uint16_t>::digits, std::uint16_t, std::conditional_t<bits <= std::numeric_limits<std::uint32_t>::digits, std::uint32_t, std::uint64_t>>>;
```
