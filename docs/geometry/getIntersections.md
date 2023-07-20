# [xieite](../xieite.md)::[geometry](../geometry.md)::getIntersections
Defined in header [<xieite/geometry/getIntersections.hpp>](../../include/xieite/geometry/getIntersections.hpp)

<br/>

Calculates all intersections between two geometrical elements

<br/><br/>

## Synopses

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point`
- `point2` - Another `xieite::geometry::Point`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point`
- `linearShape` - A value of any type satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point`
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, xieite::geometry::Point point) noexcept;
```
### Parameters
- `linearShape` - A constant reference to a value of any type satisfying `xieite::concepts::LinearShape`
- `point` - A `xieite::geometry::Point`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept;
```
### Parameters
- `linearShape1` - A constant reference to a value of any type satisfying `xieite::concepts::LinearShape`
- `linearShape2` - Another constant reference to a value of any type satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `linearShape` - A constant reference to a value of any type satisfying `xieite::concepts::LinearShape`
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Points`

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `point` - A `xieite::geometry::Point`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - A constant reference to a value of any type satisfying `xieite::concepts::LinearShape`
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
- A `std::vector` of `xieite::geometry::Points`
