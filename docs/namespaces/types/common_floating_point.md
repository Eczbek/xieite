# [xieite](../../xieite.md)\:\:[types](../../types.md)\:\:CommonFractional
Defined in header [<xieite/types/common_floating_point.hpp>](../../../include/xieite/types/common_floating_point.hpp)

&nbsp;

## Description
// TODO

&nbsp;

## Synopsis
#### 1)
```cpp
template<xieite::concepts::Arithmetic... Numbers>
using CommonFractional = std::conditional_t<xieite::concepts::SameAsAny<long double, Numbers...>, long double, std::conditional_t<xieite::concepts::SameAsAll<float, Numbers...>, float, double>>;
```
