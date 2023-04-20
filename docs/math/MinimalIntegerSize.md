# `xieite::math::MinimalIntegerSize`
Defined in header [`<xieite/math/MinimalIntegerSize.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/math/MinimalIntegerSize.hpp)

<br/>

Determines the minimal signed integer type for any reasonable amount of bits. Use with `xieite::math::ConditionalIntegerSign`.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::size_t bits>
using MinimalIntegerSize = std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int8_t), std::int8_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int16_t), std::int16_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int32_t), std::int32_t, std::int64_t>>>;
```
### Template parameters
- `bits` - A `std::size_t` copy
