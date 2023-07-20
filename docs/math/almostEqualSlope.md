# [xieite](../xieite.md)::[math](../math.md)::almostEqualSlope
Defined in header [<xieite/math/almostEqualSlope.hpp>](../../include/xieite/math/almostEqualSlope.hpp)

<br/>

Checks whether two slopes are almost equal

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr bool almostEqualSlope(Number value1, Number value2) noexcept;
```
### Template parameters
- `Number1` - A type satisfying `xieite::concepts::Arithmetic`
- `Number2` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value1` - A `Number1`
- `value2` - A `Number2`
### Return value
- A `bool`
