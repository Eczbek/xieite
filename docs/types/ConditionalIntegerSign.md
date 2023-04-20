# `xieite::types::ConditionalIntegerSign`
Defined in header [`<xieite/types/ConditionalIntegerSign.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/types/ConditionalIntegerSign.hpp)

<br/><br/>

## Synopsis

<br/>

```cpp
template<std::integral Integral, bool sign>
using ConditionalIntegerSign = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
```
### Template parameters
- `Integral` - An integral type, satisfying `std::integral`
- `sign` - A `bool` copy
