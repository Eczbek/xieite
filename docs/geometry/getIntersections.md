# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getIntersections`
Defined in header [`<xieite/geometry/getIntersections.hpp>`](../../include/xieite/geometry/getIntersections.hpp)

<br/>

Calculates all intersections between two geometrical elements.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
### Parameters
- `polygon1` - A `xieite::geometry::Polygon` constant reference
- `polygon2` - A `xieite::geometry::Polygon` constant reference
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- `std::vector` of `xieite::geometry::Point` - All found intersections

<br/><br/>

## See also
- [`xieite::concepts::LinearShape`](../../docs/concepts/LinearShape.md)
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
- [`xieite::geometry::Line`](../../docs/geometry/Line.md)
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
- [`xieite::geometry::Polygon`](../../docs/geometry/Polygon.md)
- [`xieite::geometry::Ray`](../../docs/geometry/Ray.md)
- [`xieite::geometry::Segment`](../../docs/geometry/Segment.md)
