# [xieite](../xieite.md)\:\:[math](../math.md)\:\:AttemptUnsign
Defined in header [<xieite/math/AttemptUnsign.hpp>](../../include/xieite/math/AttemptUnsign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Any>
using AttemptUnsign = std::conditional_t<std::signed_integral<Any>, std::make_unsigned<Any>, std::type_identity<Any>>::type;
```
