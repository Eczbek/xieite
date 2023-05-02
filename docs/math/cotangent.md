# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::cotangent`
Defined in header [`<xieite/math/cotangent.hpp>`](../../include/xieite/math/cotagent.hpp)

<br/>

A trigonometric function which wasn't included in the standard math library. Calculates the cotangent of a value.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number cotangent(Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - A `Number` copy
### Return value
- A `Number`, the cotangent of `value`

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
