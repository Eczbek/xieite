# [xieite](../../xieite.md)\:\:[math](../../math.md)\:\:logarithm
Defined in header [<xieite/math/logarithm.hpp"](../../../include/xieite/math/logarithm.hpp)

&nbsp;

## Description
Takes the logarithm of a value in any base.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
[[nodiscard]] constexpr std::common_type_t<double, Number1, Number2> logarithm(Number1 base, Number2 value) noexcept;
```
