# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Point](../../../Point.md)\:\:operator==
Defined in header [<xieite/geometry/Point.hpp>](../../../../../include/xieite/geometry/Point.hpp)

&nbsp;

## Description
Compares two points.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr bool operator==(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/toRadians.hpp>

int main() {
    xieite::geometry::Point point1(1, 0);
    
    xieite::geometry::Point point2(0, 1);
    
    point1 = xieite::geometry::rotate(point1, xieite::math::toRadians(90));
    
    std::cout
        << std::boolalpha
        << '(' << point1.x << ", " << point1.y << ")\n"
        << '(' << point2.x << ", " << point2.y << ")\n"
        << (point1 == point2) << '\n';
}
```
Output:
```
(6.12323e-17, 1)
(0, 1)
true
```
    