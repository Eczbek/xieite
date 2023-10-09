# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Line](../../../line.md)\:\:containsPoint
Defined in header [<xieite/geometry/line.hpp>](../../../../../../include/xieite/geometry/line.hpp)

&nbsp;

## Description
Checks whether this line contains a point.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr bool containsPoint(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/line.hpp>

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
