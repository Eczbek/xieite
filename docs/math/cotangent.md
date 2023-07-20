# [xieite](../xieite.md)::[math](../math.md)::cotangent
Defined in header [<xieite/math/cotangent.hpp>](../../include/xieite/math/cotagent.hpp)

<br/>

Calculates the cotangent of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr xieite::math::Result<Number> cotangent(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number`
### Return value
- A `xieite::math::Result` of `Number`
