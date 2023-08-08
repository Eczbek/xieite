# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getIntersections
Defined in header [<xieite/geometry/getIntersections.hpp>](../../include/xieite/geometry/getIntersections.hpp)

&nbsp;

## Description
Calculates all intersections between two geometrical elements

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### Function parameters
- `point1` - A `xieite::geometry::Point`
- `point2` - Another `xieite::geometry::Point`
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const LinearShape& linearShape) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `linearShape` - A constant `LinearShape` reference
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept;
```
#### Function parameters
- `point` - A `xieite::geometry::Point`
- `polygon` - A `xieite::geometry::Polygon` constant reference
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Point point) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A constant `LinearShape` reference
- `point` - A `xieite::geometry::Point`
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept;
```
#### Template parameters
- `LinearShape1` - A type satisfying `xieite::concepts::LinearShape`
- `LinearShape2` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape1` - A constant `LinearShape1` reference
- `linearShape2` - Another constant `LinearShape2` reference
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Polygon& polygon) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `linearShape` - A constant `LinearShape` reference
- `polygon` - A `xieite::geometry::Polygon` constant reference
#### Return type
- `std::vector` of `xieite::geometry::Points`

&nbsp;

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `point` - A `xieite::geometry::Point`
#### Return type
- `std::vector` of `xieite::geometry::Point`s. In this case, only one intersection is possible

&nbsp;

```cpp
template<xieite::concepts::LinearShape LinearShape>
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const LinearShape& linearShape) noexcept;
```
#### Template parameters
- `LinearShape` - A type satisfying `xieite::concepts::LinearShape`
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference
- `linearShape` - A constant `LinearShape` reference
#### Return type
- `std::vector` of `xieite::geometry::Point`s

&nbsp;

```cpp
[[nodiscard]]
constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept;
```
#### Function parameters
- `polygon1` - A `xieite::geometry::Polygon` constant reference
- `polygon2` - Another `xieite::geometry::Polygon` constant reference
#### Return type
- `std::vector` of `xieite::geometry::Points`
