# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:scale
Defined in header [<xieite/geometry/scale.hpp"](../../../include/xieite/geometry/scale.hpp)

&nbsp;

## Description
Scales a shape.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr xieite::geometry::Point scale(xieite::geometry::Point point, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr LinearShape scale(const LinearShape& linearShape, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr xieite::geometry::Polygon scale(xieite::geometry::Polygon polygon, double scale, xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept;
```
