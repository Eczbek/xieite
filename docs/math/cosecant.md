# `xieite::math::cosecant`
Defined in header [`<xieite/math/cosecant.hpp>`](../../include/xieite/math/cosecant.hpp)

<br/>

A trigonometric function which wasn't included in the standard math library. Calculates the cosecant of a value.

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number cosecant(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number` copy
### Return value
- A `Number`, the cosecant of `value`

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
