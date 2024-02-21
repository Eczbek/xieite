# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:Ray
Defined in header [<xieite/geometry/ray.hpp"](../../../include/xieite/geometry/ray.hpp)

&nbsp;

## Description
A structure for representing an infinite ray with one end.

&nbsp;

## Synopses
#### 1)
```cpp
struct Ray {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Ray(xieite::geometry::Point, xieite::geometry::Point);

    constexpr Ray(xieite::geometry::Point, double);

    friend constexpr bool operator==(const xieite::geometry::Ray&);

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
- [Ray](./structures/ray/1/operators/constructor.md)
- [operator==](./structures/ray/1/operators/equal.md)
- [angle](./structures/ray/1/angle.md)
- [containsPoint](./structures/ray/1/contains_point.md)
- [length](./structures/ray/1/length.md)
- [slope](./structures/ray/1/slope.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/ray.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 })
            .containsPoint({ -1.0, -1.0 })
        << '\n';
}
```
Output:
```
false
```
