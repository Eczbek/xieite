# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:AttemptSign
Defined in header [<xieite/math/attempt_sign.hpp>](../../../include/xieite/math/attempt_sign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
using AttemptSign = std::conditional_t<xieite::concepts::UnsignedInteger<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
```
