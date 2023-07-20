# [xieite](../xieite.md)::[math](../math.md)::toRadians
Defined in header [<xieite/math/toRadians.hpp>](../../include/xieite/math/toRadians.hpp)

<br/>

Converts degrees to radians

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr xieite::math::Result<Number> toRadians(Number degrees) noexcept;
```
### Template parameters
- `Number` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `degrees` - A `Number`
### Return value
- A `xieite::math::Result` of `Number`, equal to degrees in radians
