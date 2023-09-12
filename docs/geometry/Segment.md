# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Segment
Defined in header [<xieite/geometry/Segment.hpp>](../../include/xieite/geometry/Segment.hpp)

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
- [Segment](./Segment/1/operators/constructor.md)
- [operator==](./Segment/1/operators/equal.md)
- [angle](./Segment/1/angle.md)
- [containsPoint](./Segment/1/containsPoint.md)
- [length](./Segment/1/length.md)
- [slope](./Segment/1/slope.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>

int main() {
    std::cout << xieite::geometry::getLength(xieite::geometry::Segment({ 0.0, 0.0 }, { 3.0, 4.0 })) << '\n';
}
```
Output:
```
5
```
