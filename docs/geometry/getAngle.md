# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getAngle
Defined in header [<xieite/geometry/getAngle.hpp>](../../include/xieite/geometry/getAngle.hpp)

&nbsp;

## Description
Calculates the angle of a line or between two points, in radians.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double getAngle(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
constexpr double getAngle(const LinearShape& linearShape) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getAngle.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
    xieite::geometry::Point end(1.0, 0.0);
    xieite::geometry::Line line(start, end);
    std::cout << xieite::geometry::getAngle(line) << '\n';
}
```
Output (rounded):
```
0
```
