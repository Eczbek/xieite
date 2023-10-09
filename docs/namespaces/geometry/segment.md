# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Segment
Defined in header [<xieite/geometry/segment.hpp>](../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
A structure for representing a finite line segment.

&nbsp;

## Synopses
#### 1)
```cpp
struct Segment {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Segment(xieite::geometry::Point, xieite::geometry::Point);

    friend constexpr bool operator==(const xieite::geometry::Segment&);

    constexpr double angle() const;

    constexpr bool containsPoint(xieite::geometry::Point) const;

    constexpr double length() const;

    constexpr double slope() const;
};
```
##### Member variables
- start
- end
##### Member functions
- [Segment](./structures/segment/1/operators/constructor.md)
- [operator==](./structures/segment/1/operators/equal.md)
- [angle](./structures/segment/1/angle.md)
- [containsPoint](./structures/segment/1/contains_point.md)
- [length](./structures/segment/1/length.md)
- [slope](./structures/segment/1/slope.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/segment.hpp>

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 }).length() << '\n';
}
```
Output:
```
5
```
