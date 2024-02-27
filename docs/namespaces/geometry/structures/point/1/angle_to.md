# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point](../../../point.md)\:\:angleTo
Defined in header [<xieite/geometry/point.hpp>](../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Computes the angle between this and another point.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double angleTo(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/point.hpp"

int main() {
    std::cout << xieite::geometry::Point(0.0, 0.0).angleTo({ 1.0, 1.0 }) << '\n';
}
```
Output:
```
0.785398
```
