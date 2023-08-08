# [xieite](../xieite.md)\:\:[math](../math.md)\:\:cotangent
Defined in header [<xieite/math/cotangent.hpp>](../../include/xieite/math/cotagent.hpp)

&nbsp;

## Description
Calculates the cotangent of a value

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> cotangent(Arithmetic value) noexcept;
```
#### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
#### Function parameters
- `value` - An `Arithmetic`
#### Return type
- `xieite::math::Result` of `Arithmetic`
