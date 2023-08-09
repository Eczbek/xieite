# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getDistance
Defined in header [<xieite/geometry/getDistance.hpp>](../../include/xieite/geometry/getDistance.hpp)

&nbsp;

## Description
Calculates the distance between two points.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double getDistance(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getDistance.hpp>

int main() {
    xieite::geometry::Point point1(0.0, 0.0);
    xieite::geometry::Point point2(3.0, 4.0);

    std::cout << xieite::geometry::getDistance(point1, point2) << '\n';
}
```
Output:
```
5
```
