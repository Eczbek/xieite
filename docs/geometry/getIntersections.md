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
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const LinearShape& linearShape) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `point` - A `xieite::geometry::Point`
- `linearShape` - A constant `LinearShape` reference
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
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Point point) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A constant `LinearShape` reference
- `point` - A `xieite::geometry::Point`
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept;
```
### Template parameters
- `LinearShape1` - A type satisfying `xieite::concepts::LinearShape`
- `LinearShape2` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape1` - A constant `LinearShape1` reference
- `linearShape2` - Another constant `LinearShape2` reference
### Return value
- A `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

<br/><br/>

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `linearShape` - A constant `LinearShape` reference
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
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const LinearShape& linearShape) noexcept;
```
### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
### Parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - A constant `LinearShape` reference
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
