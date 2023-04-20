# `xieite::types::OptimalIntegerSize`
Defined in header [`<xieite/types/OptimalIntegerSize.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/types/OptimalIntegerSize.hpp)

<br/>

Determines the optimal signed integer type for any reasonable amount of bits. Use with `xieite::types::ConditionalIntegerSign`.

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::size_t bits>
using OptimalIntegerSize = std::conditional_t<bits <= (sizeof(short) * CHAR_BIT), short, std::conditional_t<bits <= (sizeof(int) * CHAR_BIT), int, std::conditional_t<bits <= (sizeof(long) * CHAR_BIT), long, long long>>>;
```
### Template parameters
- `bits` - A `std::size_t` copy
