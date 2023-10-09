# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Polygon
Defined in header [<xieite/geometry/polygon.hpp>](../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
A structure for representing a polygon.

&nbsp;

## Synopses
#### 1)
```cpp
struct Polygon {
    std::vector<xieite::geometry::Point> points;

    template<xieite::concepts::RangeOf<xieite::geometry::Point> Range = std::vector<xieite::geometry::Point>>
    constexpr Polygon(const Range&);

    friend constexpr bool operator==(const xieite::geometry::Polygon&);

    constexpr double area() const;

    constexpr bool containsPoint(xieite::geometry::Point) const;

    constexpr double perimeter() const;

    constexpr std::vector<xieite::geometry::Segment> sides() const;
};
```
##### Member variables
- points
##### Member functions
- [Polygon](./structures/polygon/1/operators/constructor.md)
- [operator==](./structures/polygon/1/operators/equal.md)
- [area](./structures/polygon/1/area.md)
- [containsPoint](./structures/polygon/1/contains_point.md)
- [perimeter](./structures/polygon/1/perimeter.md)
- [sides](./structures/polygon/1/sides.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/polygon.hpp>

int main() {
    std::cout
        << xieite::geometry::Polygon({
            { 1.0, 0.0 },
            { 2.0, 1.0 },
            { 1.0, 2.0 },
            { 0.0, 1.0 }
        })
            .area()
        << '\n';
}
```
Output:
```
1
```
