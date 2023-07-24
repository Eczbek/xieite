# [xieite](../xieite.md)::[math](../math.md)::almostEqualSlope
Defined in header [<xieite/math/almostEqualSlope.hpp>](../../include/xieite/math/almostEqualSlope.hpp)

<br/>

Checks whether two slopes are almost equal

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Arithmetic1, xieite::concepts::Arithmetic Arithmetic2>
[[nodiscard]]
constexpr bool almostEqualSlope(const Arithmetic1 value1, const Arithmetic2 value2) noexcept;
```
### Template parameters
- `Arithmetic1` - A type satisfying `xieite::concepts::Arithmetic`
- `Arithmetic2` - A type satisfying `xieite::concepts::Arithmetic`
### Parameters
- `value1` - An `Arithmetic1`
- `value2` - An `Arithmetic2`
### Return value
- A `bool`
