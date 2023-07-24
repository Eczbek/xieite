# [xieite](../xieite.md)::[math](../math.md)::toDegrees
Defined in header [<xieite/math/toDegrees.hpp>](../../include/xieite/math/toDegrees.hpp)

<br/>

Converts radians to degrees

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> toDegrees(Arithmetic radians) noexcept;
```
### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `radians` - An `Arithmetic`
### Return value
- A `xieite::math::Result` of `Arithmetic`, equal to radians in degrees
