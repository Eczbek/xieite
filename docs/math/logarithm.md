# [xieite](../xieite.md)::[math](../math.md)::logarithm
Defined in header [<xieite/math/logarithm.hpp>](../../include/xieite/math/logarithm.hpp)

<br/>

Takes the logarithm of a value of any base

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
[[nodiscard]]
constexpr xieite::math::Result<Number1, Number2> logarithm(const Number1 base, const Number2 value) noexcept;
```
### Template parameters
- `Number1` - A type satisfying `xieite::concepts::Arithmetic`
- `Number2` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `base` - A `Number1`
- `value` - A `Number2`
### Return value
- A `xieite::math::Result` of `Number1` and `Number2`
