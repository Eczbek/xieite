# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Segment](../../../segment.md)\:\:containsPoint
Defined in header [<xieite/geometry/segment.hpp>](../../../../../../include/xieite/geometry/segment.hpp)

&nbsp;

## Description
Checks whether this segment contains a point.

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
#include "xieite/geometry/segment.hpp"

int main() {
    std::cout
        << std::boolalpha
        << xieite::geometry::Segment({ 0.0, 0.0 }, { 1.0, 1.0 })
            .containsPoint({ -1.0, -1.0 })
        << '\n';
}
```
Output:
```
false
```
