# [xieite](../xieite.md)\:\:[math](../math.md)\:\:toDegrees
Defined in header [<xieite/math/toDegrees.hpp>](../../include/xieite/math/toDegrees.hpp)

&nbsp;

## Description
Converts radians to degrees

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> toDegrees(Arithmetic radians) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `radians` - An `Arithmetic`
#### Return type
- `xieite::math::Result` of `Arithmetic`, equal to radians in degrees
