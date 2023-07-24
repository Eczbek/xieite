# [xieite](../xieite.md)::[math](../math.md)::secant
Defined in header [<xieite/math/secant.hpp>](../../include/xieite/math/secant.hpp)

<br/>

Calculates the secant of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> secant(Arithmetic value) noexcept;
```
### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - An `Arithmetic`
### Return value
- A `xieite::math::Result` of `Arithmetic`
