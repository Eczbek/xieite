# [xieite](../../xieite.md)\:\:[geometry](../../geometry.md)\:\:[Ray](../Ray.md)\:\:Ray
Defined in header [<xieite/geometry/Ray.hpp>](../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray`

&nbsp;

## Synopsis
```cpp
constexpr Ray(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
#### Function parameters
- `start` - A `xieite::geometry::Point`, the start of the ray
- `end` - A `xieite::geometry::Point`, an intersection through which the infinite ray passes

&nbsp;

```cpp
constexpr Ray(xieite::geometry::Point start, double angle) noexcept;
```
#### Function parameters
- `start` - A `xieite::geometry::Point`, the start of the ray
- `angle` - A `double`, the ray's angle

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
    xieite::geometry::Point start(0.0, 0.0);
    xieite::geometry::Point end(1.0, 1.0);
    xieite::geometry::Point point(-1.0, -1.0);

    xieite::geometry::Ray ray(stat, end);

    std::cout
        << std::boolalpha
        << xieite::geometry::containsPoint(ray, point) << '\n';
}
```
Output:
```
false
```
