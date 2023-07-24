# [xieite](../xieite.md)::[math](../math.md)::cosecant
Defined in header [<xieite/math/cosecant.hpp>](../../include/xieite/math/cosecant.hpp)

<br/>

Calculates the cosecant of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> cosecant(Arithmetic value) noexcept;
```
### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - An `Arithmetic`
### Return value
- A `xieite::math::Result` of `Arithmetic`
