# [xieite](../xieite.md)\:\:[geometry](../geometry.md)\:\:getPerimeter
Defined in header [<xieite/geometry/getPerimeter.hpp>](../../include/xieite/geometry/getPerimeter.hpp)

&nbsp;

## Description
Calculates the perimeter of a polygon.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]]
constexpr double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/getPerimeter.hpp>

int main() {
    std::cout << xieite::geometry::getPerimeter(xieite::geometry::Polygon({
        { -1.0, -1.0 },
        { 1.0, -1.0 },
        { 1.0, 1.0 },
        { -1.0, 1.0 }
    })) << '\n';
}
```
Output:
```
8
```
