# [xieite](../../../xieite.md)\:\:[geometry](../../../geometry.md)\:\:[Line](../../Line.md)\:\:containsPoint
Defined in header [<xieite/geometry/Line.hpp>](../../../../include/xieite/geometry/Line.hpp)

&nbsp;

## Description
Checks whether this line contains a point.

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
#include <xieite/geometry/Line.hpp>

int main() {
    std::cout
        << std::boolalpha
        << xieite::geometry::Line({ 0.0, 0.0 }, { 1.0, 1.0 })
            .containsPoint({ -1.0, -1.0 })
        << '\n';
}
```
Output:
```
true
```
