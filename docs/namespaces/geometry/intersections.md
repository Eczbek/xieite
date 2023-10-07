# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:intersections
Defined in header [<xieite/geometry/intersections.hpp>](../../../include/xieite/geometry/intersections.hpp)

&nbsp;

## Description
Computes all intersections between two geometrical elements.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(xieite::geometry::Point point, const LinearShape& linearShape) noexcept;
```
#### 3)
```cpp
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept;
```
#### 4)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape& linearShape, xieite::geometry::Point point) noexcept;
```
#### 5)
```cpp
template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept;
```
#### 6)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
#### 7)
```cpp
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
#### 8)
```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon, const LinearShape& linearShape) noexcept;
```
#### 9)
```cpp
[[nodiscard]] constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
