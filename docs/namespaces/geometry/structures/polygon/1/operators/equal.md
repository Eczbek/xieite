# [xieite](../../../../../../xieite.md)\:\:[geometry](../../../../../../geometry.md)\:\:[Polygon<Arithmetic>](../../../../polygon.md)\:\:operator==\(\)
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Compares two polygons.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon<Arithmetic>& polygon1, const xieite::geometry::Polygon<Arithmetic>& polygon2) noexcept;
```

&nbsp;

## Example
```cpp
#include <print>
#include "xieite/geometry/polygon.hpp"

int main() {
    auto polygon1 = xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    });

    auto polygon2 = xieite::geometry::Polygon({
        { 0.0, 2.0 },
        { 2.0, 2.0 },
        { 2.0, 0.0 },
        { 0.0, 0.0 }
    });

    std::println("{}", polygon1 == polygon2);
}
```
Output:
```
true
```
