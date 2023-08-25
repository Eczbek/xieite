# [xieite](../xieite.md)\:\:[math](../math.md)\:\:Result
Defined in header [<xieite/math/Result.hpp>](../../include/xieite/math/Result.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
using Result = std::conditional_t<xieite::concepts::SameAsAnyOf<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAllOf<float, Numbers...>, float, double>>;
```
