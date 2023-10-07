# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Segment
Defined in header [<xieite/geometry/Segment.hpp>](../../../include/xieite/geometry/Segment.hpp)

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
- [Segment](./structures/Segment/1/operators/constructor.md)
- [operator==](./structures/Segment/1/operators/equal.md)
- [angle](./structures/Segment/1/angle.md)
- [containsPoint](./structures/Segment/1/containsPoint.md)
- [length](./structures/Segment/1/length.md)
- [slope](./structures/Segment/1/slope.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>

int main() {
    std::cout << xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 }).length() << '\n';
}
```
Output:
```
5
```
