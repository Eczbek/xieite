# [xieite](../../../../../xieite.md)\:\:[geometry](../../../../../geometry.md)\:\:[Point](../../../Point.md)\:\:angleTo
Defined in header [<xieite/geometry/Point.hpp>](../../../../../../include/xieite/geometry/Point.hpp)

&nbsp;

## Description
Computes the angle between this and another point.

&nbsp;

## Synopses
#### 1)
```cpp
[[nodiscard]] constexpr double angleTo(xieite::geometry::Point point) const noexcept;
```

&nbsp;

## Example
```cpp
#include <iostream>
#include <xieite/geometry/Point.hpp>

int main() {
    std::cout << xieite::geometry::Point(0.0, 0.0).angleTo({ 1.0, 1.0 }) << '\n';
}
```
Output:
```
0.785398
```
