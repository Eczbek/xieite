# [xieite](../xieite.md)\:\:[math](../math.md)\:\:logarithm
Defined in header [<xieite/math/logarithm.hpp>](../../include/xieite/math/logarithm.hpp)

&nbsp;

## Description
Takes the logarithm of a value of any base.

&nbsp;

## Synopses
#### 1)
```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic1, Arithmetic2> logarithm(Arithmetic1 base, Arithmetic2 value) noexcept;
```
