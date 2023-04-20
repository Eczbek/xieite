# `xieite::math::secant`
Defined in header [`<xieite/math/secant.hpp>`](https://github.com/Eczbek/xieite/tree/main/include/xieite/math/secant.hpp)

<br/>

A trigonometric function which wasn't included in the standard math library. Calculates the secant of a value.

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
- A `Number`, the secant of `value`

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](https://github.com/Eczbek/xieite/tree/main/docs/concepts/Arithmetic.md)
