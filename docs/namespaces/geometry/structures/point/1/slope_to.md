# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point](../../../point.md)\:\:slopeTo
Defined in header [<xieite/geometry/point.hpp>](../../../../../../include/xieite/geometry/point.hpp)

&nbsp;

## Description
Computes the slope from this to another point.

&nbsp;

## Synopsis
#### 1)
```cpp
[[nodiscard]] constexpr double slopeTo(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include "xieite/geometry/point.hpp"

int main() {
    std::cout << xieite::geometry::Point(0.0, 0.0).slopeTo({ 1.0, 1.0 }) << '\n';
}
```
Output:
```
1
```
