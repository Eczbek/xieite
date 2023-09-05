# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Segment
Defined in header [<xieite/geometry/Segment.hpp>](../../include/xieite/geometry/Segment.hpp)

&nbsp;

## Description
A struct representing a finite line segment.

&nbsp;

## Synopses
#### 1)
```cpp
struct Segment {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Segment(xieite::geometry::Point, xieite::geometry::Point);

    constexpr bool operator==(const xieite::geometry::Segment&) const;
};
```
##### Member variables
- start
- end
##### Member functions
- [Segment](./Segment/1/constructor.md)
- [operator==](./Segment/1/operatorEquals.md)

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
