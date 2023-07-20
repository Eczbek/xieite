# [xieite](../xieite.md)::[math](../math.md)::cosecant
Defined in header [<xieite/math/cosecant.hpp>](../../include/xieite/math/cosecant.hpp)

<br/>

Calculates the cosecant of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr xieite::math::Result<Number> cosecant(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number`
### Return value
- A `xieite::math::Result` of `Number`
