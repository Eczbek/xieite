# [xieite](../xieite.md)::[math](../math.md)::toRadians
Defined in header [<xieite/math/toRadians.hpp>](../../include/xieite/math/toRadians.hpp)

<br/>

Converts degrees to radians

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> toRadians(Arithmetic degrees) noexcept;
```
### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `degrees` - An `Arithmetic`
### Return value
- A `xieite::math::Result` of `Arithmetic`, equal to degrees in radians
