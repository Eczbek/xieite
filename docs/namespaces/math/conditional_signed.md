# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:ConditionalSigned
Defined in header [<xieite/math/conditional_signed.hpp>](../../../include/xieite/math/conditional_signed.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Integer Integer, bool sign>
using ConditionalSigned = std::conditional_t<sign, std::make_signed_t<Integer>, std::make_unsigned_t<Integer>>;
```
