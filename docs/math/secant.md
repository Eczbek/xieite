# [xieite](../xieite.md)\:\:[math](../math.md)\:\:secant
Defined in header [<xieite/math/secant.hpp>](../../include/xieite/math/secant.hpp)

&nbsp;

## Description
Calculates the secant of a value

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> secant(Arithmetic value) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value` - An `Arithmetic`
#### Return type
- `xieite::math::Result` of `Arithmetic`
