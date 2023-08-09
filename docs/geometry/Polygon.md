# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Polygon
Defined in header [<xieite/geometry/Polygon.hpp>](../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
A class representing a polygon.

&nbsp;

## Synopses
#### 1)
```cpp
struct Polygon {
    std::vector<xieite::geometry::Point> points;

    template<xieite::concepts::RangeOf<xieite::geometry::Point> PointRange>
    constexpr Polygon(const PointRange& points);

    constexpr bool operator==(const xieite::geometry::Polygon&) const;
};
```
##### Member variables
- points
##### Member functions
- [Polygon](./Polygon/constructor.md)
- [operator==](./Polygon/operatorEquals.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getArea.hpp>

int main() {
    std::cout << xieite::geometry::getArea(xieite::geometry::Polygon({
        { 1.0, 0.0 },
        { 2.0, 1.0 },
        { 1.0, 2.0 },
        { 0.0, 1.0 }
    })) << '\n';
}
```
Output:
```
1
```
