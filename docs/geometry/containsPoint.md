# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:containsPoint
Defined in header [<xieite/geometry/containsPoint.hpp>](../../include/xieite/geometry/containsPoint.hpp)

&nbsp;

## Description
Checks whether a point lies within or on the border of a shape.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Line& line, xieite::geometry::Point point) noexcept;
```
#### 2)
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Ray& ray, xieite::geometry::Point point) noexcept;
```
#### 3)
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Segment& segment, xieite::geometry::Point point) noexcept;
```
#### 4)
```cpp
[[nodiscard]]
constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, xieite::geometry::Point point) noexcept;
```

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
