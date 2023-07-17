# [xieite](../xieite.md)::[math](../math.md)::logarithm
Defined in header [<xieite/math/logarithm.hpp>](../../include/xieite/math/logarithm.hpp)

<br/>

Takes the logarithm of a value to a base

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number logarithm(const Number base, const Number value) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `base` - A `Number` copy
- `value` - Another `Number` copy
### Return value
- A `Number`, the logarithm
