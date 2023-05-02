# [`xieite`](../../README.md)`::`[`math`](../../docs/math.md)`::toRadians`
Defined in header [`<xieite/math/toRadians.hpp>`](../../include/xieite/math/toRadians.hpp)

<br/>

Converts degrees to radians.

<br/><br/>

## Synopsis

<br/><br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number toRadians(Number degrees) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `degrees` - A `Number` copy
### Return value
- A `Number`, equal to `degrees` in radians

<br/><br/>

## See also
- [`xieite::concepts::Arithmetic`](../../docs/concepts/Arithmetic.md)
