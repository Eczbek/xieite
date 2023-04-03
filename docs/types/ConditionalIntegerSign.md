# xieite::types::ConditionalIntegerSign
Defined in header `<xieite/types/ConditionalIntegerSign.hpp>`

<br/><br/>

## Declarations
```cpp
template<std::integral Integral, bool sign>
using ConditionalIntegerSign = std::conditional_t<sign, std::make_signed_t<Integral>, std::make_unsigned_t<Integral>>;
```
