# [xieite](../xieite.md)::[math](../math.md)::cotangent
Defined in header [<xieite/math/cotangent.hpp>](../../include/xieite/math/cotagent.hpp)

<br/>

Calculates the cotangent of a value

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic>
[[nodiscard]]
constexpr xieite::math::Result<Arithmetic> cotangent(Arithmetic value) noexcept;
```
### Template parameters
- `Arithmetic` - An arithmetic type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value` - An `Arithmetic`
### Return value
- A `xieite::math::Result` of `Arithmetic`
