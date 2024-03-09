# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon<Number>](../../../polygon.md)\:\:sides
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Returns the sides of this polygon.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr std::vector<xieite::geometry::Segment> sides() const noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    for (const auto& side : polygon.sides()) {
        std::println("({}, {}) -> ({}, {})", side.start.x, side.start.y, side.end.x, side.end.y);
    }
}
```
Possible output:
```
(0, 0) -> (2, 0)
(2, 0) -> (2, 2)
(2, 2) -> (0, 2)
(0, 2) -> (0, 0)
```
