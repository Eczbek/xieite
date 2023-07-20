# [xieite](../xieite.md)::[math](../math.md)::secant
Defined in header [<xieite/math/secant.hpp>](../../include/xieite/math/secant.hpp)

<br/>

Calculates the secant of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr xieite::math::Result<Number> secant(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number`
### Return value
- A `xieite::math::Result` of `Number`
