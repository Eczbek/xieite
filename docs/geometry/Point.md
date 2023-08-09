# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Point
Defined in header [<xieite/geometry/Point.hpp>](../../include/xieite/geometry/Point.hpp)

&nbsp;

## Description
A class representing a point.

&nbsp;

## Synopses
#### 1)
```cpp
struct Point {
    double x;
    double y;

    constexpr Point(double = 0, double = 0);

    constexpr bool operator==(xieite::geometry::Point) const;
};
```
##### Member variables
- x
- y
##### Member functions
- [Point](./Point/constructor.md)
- [operator==](./Point/operatorEquals.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point point = xieite::geometry::rotate(xieite::geometry::Point(1, 0), xieite::math::toRadians(90));
    
    std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
