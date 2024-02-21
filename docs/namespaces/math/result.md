# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:Result
Defined in header [<xieite/types/common_floating_point.hpp"](../../../include/xieite/types/common_floating_point.hpp)

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
using Result = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
```
