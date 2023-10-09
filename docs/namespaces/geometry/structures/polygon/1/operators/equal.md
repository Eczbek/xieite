# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Polygon](../../../../polygon.md)\:\:operator==
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Compares two polygons.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon& polygon) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/geometry/point.hpp>
#include <xieite/geometry/polygon.hpp>

int main() {
    auto polygon1 = xieite::geometry::Polygon({
        { 0, 0 },
        { 2, 0 },
        { 2, 2 },
        { 0, 2 }
    });

    auto polygon2 = xieite::geometry::Polygon({
        { 0, 2 },
        { 2, 2 },
        { 2, 0 },
        { 0, 0 }
    });

    std::cout
        << std::boolalpha
        << (polygon1 == polygon2)
        << '\n';
}
```
Output:
```
true
```
