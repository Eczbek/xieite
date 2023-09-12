# [xieite](../../../../xieite.md)\:\:[geometry](../../../../geometry.md)\:\:[Polygon](../../../Polygon.md)\:\:operator==
Defined in header [<xieite/geometry/Polygon.hpp>](../../../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Compares two polygons.

&nbsp;

## Synopses
#### 1)
```cpp
friend constexpr bool operator==(const xieite::geometry::Polygon& polygon) noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <vector>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>

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
