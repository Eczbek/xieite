# [xieite](../xieite.md)\:\:[math](../math.md)\:\:AttemptSign
Defined in header [<xieite/math/AttemptSign.hpp>](../../include/xieite/math/AttemptSign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
using AttemptSign = std::conditional_t<std::unsigned_integral<Type>, std::make_signed<Type>, std::type_identity<Type>>::type;
```
