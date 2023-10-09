# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:ConditionalSign
Defined in header [<xieite/math/conditional_sign.hpp>](../../../include/xieite/math/conditional_sign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Integer Integer, bool sign>
using ConditionalSign = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
```
