# [xieite](../../README.md)::[math](../math.md)::secant
Defined in header [<xieite/math/secant.hpp>](../../include/xieite/math/secant.hpp)

<br/>

A trigonometric function which wasn't included in the standard math library. Calculates the secant of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number secant(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number` copy
### Return value
- A `Number`, the secant of value
