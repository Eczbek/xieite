# [xieite](../../xieite.md)::[geometry](../../geometry.md)::[Polygon](../Polygon.md)::operator==
Defined in header [<xieite/geometry/Polygon.hpp>](../../../include/xieite/geometry/Polygon.hpp)

<br/>

Compares two polygons to each other. Only checks that the polygons have the same points in the same relative or reversed relative order

<br/><br/>

## Synopsis

<br/>

```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- `bool` - Whether or not the compared shapes are equal
