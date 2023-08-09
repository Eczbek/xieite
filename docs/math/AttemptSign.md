# [xieite](../xieite.md)\:\:[math](../math.md)\:\:AttemptSign
Defined in header [<xieite/math/AttemptSign.hpp>](../../include/xieite/math/AttemptSign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Any>
using AttemptSign = std::conditional_t<std::unsigned_integral<Any>, std::make_signed<Any>, std::type_identity<Any>>::type;
```
