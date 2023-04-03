# xieite::types::MinimalIntegerSize
Defined in header `<xieite/types/MinimalIntegerSize.hpp>`

<br/>

Determines the minimal signed integer type for any reasonable amount of bits. Use with `xieite::types::ConditionalIntegerSign`.

<br/><br/>

## Declarations
```cpp
template<std::size_t bits>
using MinimalIntegerSize = std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int8_t), std::int8_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int16_t), std::int16_t, std::conditional_t<(bits * CHAR_BIT) <= sizeof(std::int32_t), std::int32_t, std::int64_t>>>;
```
