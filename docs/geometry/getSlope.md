# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getSlope
Defined in header [<xieite/geometry/getSlope.hpp>](../../include/xieite/geometry/getSlope.hpp)

&nbsp;

## Description
Calculates the slope of a line or between two points.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr double getSlope(xieite::geometry::Point point1, xieite::geometry::Point point2) noexcept;
```
#### 2)
```cpp
template<xieite::concepts::LinearShape LinearShape>
constexpr double getSlope(const LinearShape& linearShape) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/getSlope.hpp>

int main() {
    std::cout << xieite::geometry::getSlope(xieite::geometry::Line({ 0.0, 0.0 }, { 2.0, 3.0 })) << '\n';
}
```
Output:
```
1.5
```
