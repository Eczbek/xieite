# [xieite](../xieite.md)\:\:[math](../math.md)\:\:logarithm
Defined in header [<xieite/math/logarithm.hpp>](../../include/xieite/math/logarithm.hpp)

&nbsp;

## Description
Takes the logarithm of a value of any base.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
constexpr xieite::math::Result<Number1, Number2> logarithm(Number1 base, Number2 value) noexcept;
```
