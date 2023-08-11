# [xieite](../xieite.md)\:\:[math](../math.md)\:\:AttemptUnsign
Defined in header [<xieite/math/AttemptUnsign.hpp>](../../include/xieite/math/AttemptUnsign.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<typename Type>
using AttemptUnsign = std::conditional_t<std::signed_integral<Type>, std::make_unsigned<Type>, std::type_identity<Type>>::type;
```
