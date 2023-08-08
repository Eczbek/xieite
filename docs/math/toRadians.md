# [xieite](../xieite.md)\:\:[math](../math.md)\:\:toRadians
Defined in header [<xieite/math/toRadians.hpp>](../../include/xieite/math/toRadians.hpp)

&nbsp;

## Description
Converts degrees to radians

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> toRadians(Arithmetic degrees) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `degrees` - An `Arithmetic`
#### Return type
- `xieite::math::Result` of `Arithmetic`, equal to degrees in radians
