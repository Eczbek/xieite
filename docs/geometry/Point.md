# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Point
Defined in header [<xieite/geometry/Point.hpp>](../../include/xieite/geometry/Point.hpp)

&nbsp;

## Description
A structure for representing a point.

&nbsp;

## Synopses
#### 1)
```cpp
struct Point {
    double x;
    double y;

    constexpr Point(double = 0, double = 0);

    friend constexpr bool operator==(xieite::geometry::Point);
};
```
##### Member variables
- x
- y
##### Member functions
- [Point](./Point/1/operators/constructor.md)
- [operator==](./Point/1/operators/equal.md)
- [angleTo](./Point/1/angleTo.md)
- [distanceTo](./Point/1/distanceTo.md)
- [slopeTo](./Point/1/slopeTo.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point point = xieite::geometry::rotate({ 1.0, 0.0 }, xieite::math::toRadians(90));
    
    std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
