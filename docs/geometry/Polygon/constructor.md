# [xieite](../../xieite.md)::[geometry](../../geometry.md)::[Polygon](../Polygon.md)::Polygon
Defined in header [<xieite/geometry/Polygon.hpp>](../../../include/xieite/geometry/Polygon.hpp)

<br/>

Constructs a `xieite::geometry::Polygon`

<br/><br/>

## Synopsis

<br/>

```cpp
constexpr Polygon(const xieite::concepts::RangeOf<xieite::geometry::Point> auto& points) noexcept;
```
### Parameters
- `points` - A constant reference to a value of any type satisfying `xieite::concepts::RangeOf` of `xieite::geometry::Point`
