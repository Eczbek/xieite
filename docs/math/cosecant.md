# [xieite](../xieite.md)\:\:[math](../math.md)\:\:cosecant
Defined in header [<xieite/math/cosecant.hpp>](../../include/xieite/math/cosecant.hpp)

&nbsp;

## Description
Calculates the cosecant of a value

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> cosecant(Arithmetic value) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value` - An `Arithmetic`
#### Return type
- `xieite::math::Result` of `Arithmetic`
