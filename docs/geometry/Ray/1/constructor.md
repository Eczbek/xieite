# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Ray](../../Ray.md)\:\:Ray
Defined in header [<xieite/geometry/Ray.hpp>](../../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Constructs a `xieite::geometry::Ray`.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr Ray(xieite::geometry::Point start, xieite::geometry::Point end) noexcept;
```
#### 2)
```cpp
constexpr Ray(xieite::geometry::Point start, double angle) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

int main() {
    xieite::geometry::Ray ray(xieite::geometry::Point(0.0, 0.0), xieite::geometry::Point(1.0, 1.0));

    xieite::geometry::Point point(-1.0, -1.0);

    std::cout << std::boolalpha << xieite::geometry::containsPoint(ray, point) << '\n';
}
```
Output:
```
false
```
