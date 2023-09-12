# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Polygon](../../Polygon.md)\:\:containsPoint
Defined in header [<xieite/geometry/Polygon.hpp>](../../../../include/xieite/geometry/Polygon.hpp)

&nbsp;

## Description
Checks whether this polygon contains a point.

&nbsp;

## Synopses
#### 1)
```cpp
constexpr bool containsPoint(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>

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
