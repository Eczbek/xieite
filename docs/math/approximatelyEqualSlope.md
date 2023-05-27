# [xieite](../../README.md)::[math](../math.md)::approximatelyEqualSlope
Defined in header [<xieite/math/approximatelyEqualSlope.hpp>](../../include/xieite/math/approximatelyEqualSlope.hpp)

<br/>

Checks whether two slopes are almost equal

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr bool approximatelyEqualSlope(Number value1, Number value2) noexcept;
```
### Template parameters
- `Number` - Any arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value1` - A `Number` copy
- `value2` - Also a `Number` copy
### Return value
- A `bool`
