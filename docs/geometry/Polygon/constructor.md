# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:[Polygon](../Polygon.md)\:\:Polygon
Defined in header [<xieite/geometry/Polygon.hpp>](../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Polygon`

&nbsp;

## Synopsis
```cpp
template<xieite::concepts::RangeOf<xieite::geometry::Point> PointRange>
constexpr Polygon(const PointRange& points) noexcept;
```
#### Template parameters
- `PointRange` - A type satisfying `xieite::concepts::RangeOf` of `xieite::geometry::Point`
#### Function parameters
- `points` - A constant `PointRange` reference
