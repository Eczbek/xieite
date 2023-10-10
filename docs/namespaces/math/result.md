# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Result
Defined in header [<xieite/math/result.hpp>](../../../include/xieite/math/result.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric... Numbers>
using Result = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
```
