# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Point<Number>](../../../../point.md)\:\:operator==
Defined in header [<xieite/geometry/point.hpp>](../../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Compares two points.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(xieite::geometry::Point<Number> point1, xieite::geometry::Point<Number> point2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/rotate.hpp"
#include "xieite/literals/units.hpp"

int main() {
    using namespace xieite::literals::units;

    auto point1 = xieite::geometry::Point(1.0, 0.0);

    auto point2 = xieite::geometry::Point(0.0, 1.0);

    std::println("{}", xieite::geometry::rotate(point1, 90_degrees) == point2);
}
```
Output:
```
true
```
