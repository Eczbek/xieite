# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getIntersections`
Defined in header [`<xieite/geometry/getIntersections.hpp>`](../../include/xieite/geometry/getIntersections.hpp)

<br/>

Calculates all intersections between two geometrical elements.

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point` copy
- `point2` - Another `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `linearShape` - An `auto` copy, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, xieite::geometry::Point point) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept;
```
### Parameters
- `linearShape1` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `linearShape2` - Another `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
### Parameters
- `polygon1` - A `xieite::geometry::Polygon` constant reference
- `polygon2` - Another `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s