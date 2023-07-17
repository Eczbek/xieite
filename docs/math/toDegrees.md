# [xieite](../xieite.md)::[math](../math.md)::toDegrees
Defined in header [<xieite/math/toDegrees.hpp>](../../include/xieite/math/toDegrees.hpp)

<br/>

Converts radians to degrees

<br/><br/>

## Synopsis

<br/>

```cpp
template<xieite::concepts::Arithmetic Number>
[[nodiscard]]
constexpr Number toDegrees(Number radians) noexcept;
```
### Template parameters
- `Number` - An arithmetic type, satisfying `xieite::concepts::Arithmetic`
### Parameters
- `radians` - A `Number` copy
### Return value
- A `Number`, equal to radians in degrees
