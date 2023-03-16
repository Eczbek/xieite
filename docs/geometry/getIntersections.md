# xieite::geometry::getIntersections
Defined in header `<xieite/geometry/getIntersections.hpp>`

<br/>

Calculates all intersections between two geometrical elements.

<br/><br/>

## Declarations
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const std::derived_from<xieite::geometry::LineLike> auto& lineLike, const xieite::geometry::Polygon& polygon) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const std::derived_from<xieite::geometry::LineLike> auto& lineLike, const xieite::geometry::Ellipse& ellipse) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept;
```
```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const std::derived_from<xieite::geometry::LineLike> auto& lineLike, const xieite::geometry::Circle& circle) noexcept;
```
