# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Ray](../../Ray.md)\:\:containsPoint
Defined in header [<xieite/geometry/Ray.hpp>](../../../../include/xieite/geometry/Ray.hpp)

&nbsp;

## Description
Checks whether this ray contains a point.

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
#include <xieite/geometry/Ray.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::geometry::Ray({ 0.0, 0.0 }, { 1.0, 1.0 })
            .containsPoint({ -1.0, -1.0 })
        << '\n';
}
```
Output:
```
false
```
