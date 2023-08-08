# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:[Polygon](../Polygon.md)\:\:operator==
Defined in header [<xieite/geometry/Polygon.hpp>](../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Compares two polygons to each other. Only checks that the polygons have the same points in the same relative or reversed relative order

&nbsp;

## Synopsis
```cpp
[[nodiscard]]
constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
#### Return type
- `bool` - Whether or not the compared shapes are equal
