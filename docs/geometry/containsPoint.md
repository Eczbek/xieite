# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:containsPoint
Defined in header [<xieite/geometry/containsPoint.hpp>](../../include/xieite/geometry/containsPoint.hpp)

&nbsp;

## Description
Checks whether a point lies within or on the border of a shape

&nbsp;

## Synopses

&nbsp;

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Line& line, xieite::geometry::Point point) noexcept;
```
#### Function parameters
- `line` - A `xieite::geometry::Line` constant reference to check for a point on
- `point` - A `xieite::geometry::Point`, the point to check for
#### Return type
- `bool` - Whether or not the point lies within the shape

&nbsp;

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ray& ray, xieite::geometry::Point point) noexcept;
```
#### Function parameters
- `ray` - A `xieite::geometry::Ray` constant reference to check for a point on
- `point` - A `xieite::geometry::Point`, the point to check for
#### Return type
- `bool` - Whether or not the point lies within the shape

&nbsp;

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Segment& segment, xieite::geometry::Point point) noexcept;
```
#### Function parameters
- `segment` - A `xieite::geometry::Segment` constant reference to check for a point on
- `point` - A `xieite::geometry::Point`, the point to check for
#### Return type
- `bool` - Whether or not the point lies within the shape

&nbsp;

```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```
#### Function parameters
- `polygon` - A `xieite::geometry::Polygon` constant reference to check for a point in
- `point` - A `xieite::geometry::Point`, the point to check for
#### Return type
- `bool` - Whether or not the point lies within the shape

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
    xieite::geometry::Point point(0.0, 0.0);

    xieite::geometry::Polygon square({
        xieite::geometry::Point(-1.0, -1.0),
        xieite::geometry::Point(1.0, -1.0),
        xieite::geometry::Point(1.0, 1.0),
        xieite::geometry::Point(-1.0, 1.0)
    });

    std::cout
        << std::boolalpha
        << xieite::geometry::containsPoint(square, point) << '\n';
}
```
Output:
```
true
```
