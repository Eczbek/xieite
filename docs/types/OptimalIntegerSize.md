# xieite::types::OptimalIntegerSize
Defined in header `<xieite/types/OptimalIntegerSize.hpp>`

<br/>

Determines the optimal signed integer type for any reasonable amount of bits. Use with `xieite::types::ConditionalIntegerSign`.

<br/><br/>

## Declarations
```cpp
template<std::size_t bits>
using OptimalIntegerSize = std::conditional_t<(bits * CHAR_BIT) <= sizeof(int), int, std::conditional_t<(bits * CHAR_BIT) <= sizeof(long), long, long long>>;
```
