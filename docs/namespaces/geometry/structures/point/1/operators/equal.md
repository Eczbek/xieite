# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Point](../../../../point.md)\:\:operator==
Defined in header [<xieite/geometry/point.hpp"](../../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Compares two points.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/units/literals/angles.hpp"

int main() {
    using namespace xieite::units::literals;

    xieite::geometry::Point point1(1, 0);

    xieite::geometry::Point point2(0, 1);

    point1 = xieite::geometry::rotate(point1, 90_degrees);

    std::cout
        << std::boolalpha
        << '(' << point1.x << ", " << point1.y << ")\n"
        << '(' << point2.x << ", " << point2.y << ")\n"
        << (point1 == point2) << '\n';
}
```
Output:
```
(6.12323e-17, 1)
(0, 1)
true
```
