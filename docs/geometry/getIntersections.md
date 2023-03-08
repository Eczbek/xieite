# xieite::geometry::getIntersections
Defined in header `<xieite/geometry/getIntersections.hpp>`

<br/>

Calculates all intersections between two geometrical elements.

<br/><br/>

## Declarations
```cpp
template<std::derived_from<xieite::geometry::LineLike> L>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const L& lineLike) noexcept;
```
```cpp
template<std::derived_from<xieite::geometry::LineLike> L>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const L& lineLike, const xieite::geometry::Polygon& polygon) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
