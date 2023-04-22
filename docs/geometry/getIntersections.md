# [`xieite`](../../README.md)`::`[`geometry`](../../docs/geometry.md)`::getIntersections`
Defined in header [`<xieite/geometry/getIntersections.hpp>`](../../include/xieite/geometry/getIntersections.hpp)

<br/>

Calculates all intersections between two geometrical elements. Circle-Circle, Circle-Ellipse, and Ellipse-Ellipse intersection functions are not complete.

<br/><br/>

## Synopses

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
### Parameters
- `point1` - A `xieite::geometry::Point` copy
- `point2` - Another `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `linearShape` - An `auto` copy, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `point` - A `xieite::geometry::Point` copy
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, xieite::geometry::Point point) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept;
```
### Parameters
- `linearShape1` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `linearShape2` - Another `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
### Parameters
- `polygon1` - A `xieite::geometry::Polygon` constant reference
- `polygon2` - Another `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, xieite::geometry::Point point) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle1, const xieite::geometry::Circle& circle2) noexcept;
```
### Parameters
- `circle1` - A `xieite::geometry::Circle` constant reference
- `circle2` - A `xieite::geometry::Circle` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Ellipse& ellipse) noexcept;
```
### Parameters
- `circle` - A `xieite::geometry::Circle` constant reference
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, xieite::geometry::Point point) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
- `point` - A `xieite::geometry::Point` copy
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::concepts::LinearShape auto& linearShape) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
- `linearShape` - An `auto` constant reference, satisfying `xieite::concepts::LinearShape`
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Polygon& polygon) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
- `polygon` - A `xieite::geometry::Polygon` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Circle& circle) noexcept;
```
### Parameters
- `ellipse` - A `xieite::geometry::Ellipse` constant reference
- `circle` - A `xieite::geometry::Circle` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse1, const xieite::geometry::Ellipse& ellipse2) noexcept;
```
### Parameters
- `ellipse1` - A `xieite::geometry::Ellipse` constant reference
- `ellipse2` - Another `xieite::geometry::Ellipse` constant reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s

<br/>


<br/><br/>

## See also
- [`xieite::concepts::LinearShape`](../../docs/concepts/LinearShape.md)
- [`xieite::geometry::Circle`](../../docs/geometry/Circle.md)
- [`xieite::geometry::Ellipse`](../../docs/geometry/Ellipse.md)
- [`xieite::geometry::Point`](../../docs/geometry/Point.md)
- [`xieite::geometry::Polygon`](../../docs/geometry/Polygon.md)
