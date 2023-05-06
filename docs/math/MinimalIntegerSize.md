# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::MinimalIntegerSize`
Defined in header [`<xieite/math/MinimalIntegerSize.hpp>`](../../include/math/MinimalIntegerSize.hpp)

<br/>

Determines the minimal signed integer type for any reasonable amount of bits. Use with `xieite::math::ConditionalIntegerSign`.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<std::size_t bits>
using MinimalIntegerSize = std::conditional_t<bits <= std::numeric_limits<std::int8_t>::digits, std::int8_t, std::conditional_t<bits <= std::numeric_limits<std::int16_t>::digits, std::int16_t, std::conditional_t<bits <= std::numeric_limits<std::int32_t>::digits, std::int32_t, std::int64_t>>>;
```
### Template parameters
- `bits` - A `std::size_t` copy
### Resulting type
- The smallest signed integer type to contain `bits` amount of bits
