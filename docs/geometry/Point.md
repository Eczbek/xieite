# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Point
Defined in header [<xieite/geometry/Point.hpp>](../../include/xieite/geometry/Point.hpp)

&nbsp;

## Description
A class representing a point

&nbsp;

## Synopsis
```cpp
struct Point {
    double x;
    double y;

    constexpr Point(double = 0.0, double = 0.0);

    constexpr bool operator==(xieite::geometry::Point) const;
};
```
#### Public members
## Contents
|- x
|- y
|- <a href="./Point/constructor.md">Point</a>
`- <a href="./Point/operatorEquals.md">operator==</a>

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point point = xieite::geometry::rotate({ 1.0, 0.0 }, xieite::math::toRadians(90.0));
    
    std::cout << '(' << point.x << ", " << point.y << ")\n";
}
```
Output (rounded):
```
(0, 1)
```
