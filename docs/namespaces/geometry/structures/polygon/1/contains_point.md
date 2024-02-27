# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Polygon](../../../polygon.md)\:\:containsPoint
Defined in header [<xieite/geometry/polygon.hpp>](../../../../../../include/xieite/geometry/polygon.hpp)

&nbsp;

## Description
Checks whether this polygon contains a point.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr bool containsPoint(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/point.hpp"
#include "xieite/geometry/polygon.hpp"

int main() {
    std::cout << xieite::geometry::Polygon({
        { 0.0, 0.0 },
        { 2.0, 0.0 },
        { 2.0, 2.0 },
        { 0.0, 2.0 }
    }).containsPoint({ 1.0, 1.0 }) << '\n';
}
```
Output:
```
true
```
