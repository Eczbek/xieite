# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:Ray
Defined in header [<xieite/geometry/Ray.hpp>](../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
A struct representing an infinite ray with one end.

&nbsp;

## Synopses
#### 1)
```cpp
struct Ray {
    xieite::geometry::Point start;
    xieite::geometry::Point end;

    constexpr Ray(xieite::geometry::Point, xieite::geometry::Point);

    constexpr Ray(xieite::geometry::Point, double);

    constexpr bool operator==(const xieite::geometry::Ray&) const;
};
```
##### Member variables
- start
- end
##### Member functions
- [Ray](./Ray/1/constructor.md)
- [operator==](./Ray/1/operatorEquals.md)

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::geometry::containsPoint(xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 }), { -1.0, -1.0 }) << '\n';
}
```
Output:
```
false
```
