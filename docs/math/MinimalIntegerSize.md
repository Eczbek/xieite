# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::MinimalIntegerSize`
Defined in header [`<xieite/math/MinimalIntegerSize.hpp>`](../../include/math/MinimalIntegerSize.hpp)

<br/>

Determines the minimal unsigned integer type for any reasonable amount of bits.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::size_t bits>
using MinimalIntegerSize = std::conditional_t<bits <= std::numeric_limits<std::uint8_t>::digits, std::uint8_t, std::conditional_t<bits <= std::numeric_limits<std::uint16_t>::digits, std::uint16_t, std::conditional_t<bits <= std::numeric_limits<std::uint32_t>::digits, std::uint32_t, std::uint64_t>>>;
```
### Template parameters
- `bits` - A `std::size_t` copy
### Resulting type
- The smallest unsigned integer type to contain `bits` amount of bits
