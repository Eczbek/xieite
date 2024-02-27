# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Point
Defined in header [<xieite/geometry/point.hpp>](../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
A structure for representing a point.

&nbsp;

## Synopsis
#### 1)
```cpp
struct Point {
    double x;
    double y;

    constexpr Point(double = 0, double = 0);

    friend constexpr bool operator==(xieite::geometry::Point, xieite::geometry::Point);
};
```
##### Member variables
- x
- y
##### Member functions
- [Point](./structures/point/1/operators/constructor.md)
- [operator==](./structures/point/1/operators/equal.md)
- [angleTo](./structures/point/1/angle_to.md)
- [distanceTo](./structures/point/1/distance_to.md)
- [slopeTo](./structures/point/1/slope_to.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/units/literals/angles.hpp"

int main() {
    using namespace xieite::units::literals;

    xieite::geometry::Point point = xieite::geometry::rotate({ 1.0, 0.0 }, 90_degrees);

    std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
